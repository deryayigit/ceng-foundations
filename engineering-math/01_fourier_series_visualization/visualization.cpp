#using <System.dll>                                   // Core .NET types (String, Exception, Math, etc.)
#using <System.Drawing.dll>                           // Graphics utilities (Color, Font, Point, Size)
#using <System.Windows.Forms.dll>                     // Windows Forms UI components (Form, Button, TextBox)
#using <System.Windows.Forms.DataVisualization.dll>   // Charting library for plotting graphs

#include "fourier.h"
using namespace Fourier; // access Fourier mathematical functions and PI

// .NET namespaces used for UI components and chart rendering
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Windows::Forms::DataVisualization::Charting;
using namespace System::Globalization;

// Windows Form responsible for user input and Fourier visualization
public ref class FourierForm : public Form
{
private:

    // UI input controls
    TextBox^ txtA0;
    TextBox^ txtAN;
    TextBox^ txtBN;
    TextBox^ txtXMin;
    TextBox^ txtXMax;
    NumericUpDown^ numHarmonics;
    Button^ btnPlot;

    // Chart used to draw harmonic components and final series
    Chart^ chart;

public:
    FourierForm()
    {
        InitializeComponent();
    }

private:

    // Converts a textbox string into double using culture-independent parsing
    double ParseDouble(String^ s)
    {
        return Double::Parse(s->Trim(), CultureInfo::InvariantCulture);
    }


    // Parses comma-separated coefficient lists 
    array<double>^ ParseCoefficientList(String^ text, int expectedCount)
    {
        array<String^>^ parts = text->Split(gcnew array<wchar_t>{','},
            StringSplitOptions::RemoveEmptyEntries);

        if (parts->Length != expectedCount)
        {
            throw gcnew Exception("Katsayı sayısı N ile aynı olmalıdır.");
        }

        array<double>^ values = gcnew array<double>(expectedCount);

        for (int i = 0; i < expectedCount; i++)
        {
            values[i] = Double::Parse(parts[i]->Trim(), CultureInfo::InvariantCulture);
        }

        return values;
    }

    void ConfigurePiAxis(double xmin, double xmax)
    {
        ChartArea^ area = chart->ChartAreas["MainArea"];

        area->AxisX->CustomLabels->Clear();

        double step = PI / 2.0;

        for (int i = -4; i <= 4; i++)
        {
            double x = i * step;

            if (x < xmin || x > xmax)
                continue;

            String^ label;

            // readable π labels
            switch (i)
            {
            case -4: label = L"-2π"; break;
            case -3: label = L"-3π/2"; break;
            case -2: label = L"-π"; break;
            case -1: label = L"-π/2"; break;
            case 0:  label = L"0"; break;
            case 1:  label = L"π/2"; break;
            case 2:  label = L"π"; break;
            case 3:  label = L"3π/2"; break;
            case 4:  label = L"2π"; break;
            }

            CustomLabel^ cl = gcnew CustomLabel(
                x - step / 2,
                x + step / 2,
                label,
                0,
                LabelMarkStyle::LineSideMark
            );

            area->AxisX->CustomLabels->Add(cl);
        }
    }

    // Initializes all UI components and chart configuration
    void InitializeComponent()
    {
        this->Text = "Fourier Series Visualization";

        this->Width = 1080;
        this->Height = 1080;

        this->StartPosition = FormStartPosition::CenterScreen;
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->Font = gcnew Drawing::Font("Segoe UI", 10.0f);

        int chartWidth = 600; 
        int chartLeft = (this->Width - chartWidth) / 2;

        Label^ lblA0 = gcnew Label();
        lblA0->Text = "a0:";
        lblA0->Location = Point(chartLeft, 20);
        lblA0->AutoSize = true;

        txtA0 = gcnew TextBox();
        txtA0->Location = Point(chartLeft + 120, 18);
        txtA0->Width = 260; 
        txtA0->Text = "6.283185307179586";

        Label^ lblAN = gcnew Label();
        lblAN->Text = "a_n:";
        lblAN->Location = Point(chartLeft, 60);
        lblAN->AutoSize = true;

        txtAN = gcnew TextBox();
        txtAN->Location = Point(chartLeft + 120, 58);
        txtAN->Width = 360;
        txtAN->Text = "0,0,0";

        Label^ lblBN = gcnew Label();
        lblBN->Text = "b_n:";
        lblBN->Location = Point(chartLeft, 100);
        lblBN->AutoSize = true;

        txtBN = gcnew TextBox();
        txtBN->Location = Point(chartLeft + 120, 98);
        txtBN->Width = 360;
        txtBN->Text = "-2,-1,-0.6666667";

        Label^ lblN = gcnew Label();
        lblN->Text = "Harmonics:";
        lblN->Location = Point(chartLeft, 140);
        lblN->AutoSize = true;

        numHarmonics = gcnew NumericUpDown();
        numHarmonics->Location = Point(chartLeft + 120, 138);
        numHarmonics->Width = 120;
        numHarmonics->Minimum = 1;
        numHarmonics->Maximum = 20;
        numHarmonics->Value = 3;

        btnPlot = gcnew Button();
        btnPlot->Text = "Plot Graphic";
        btnPlot->Size = Drawing::Size(160, 40);
        btnPlot->Location = Point(chartLeft + chartWidth / 2 - 80, 200);
        btnPlot->Click += gcnew EventHandler(this, &FourierForm::OnPlotClicked);

        chart = gcnew Chart();

        chart->Size = Drawing::Size(chartWidth, 420);
        chart->Location = Point(chartLeft, 260);

        ChartArea^ area = gcnew ChartArea("MainArea");

        area->AxisX->Title = "t";
        area->AxisY->Title = "f(t)";

        area->AxisX->LabelStyle->Font = gcnew Drawing::Font("Segoe UI", 10);
        area->AxisX->Interval = PI / 2.0;

        area->AxisY->LabelStyle->Format = "F2";

        area->AxisX->MajorGrid->LineColor = Color::LightGray;
        area->AxisY->MajorGrid->LineColor = Color::LightGray;

        area->AxisX->MajorGrid->Interval = PI / 2.0;
        area->AxisX->MajorTickMark->Interval = PI / 2.0;

        area->AxisX->IsMarginVisible = false;
        area->AxisX->Minimum = -2 * PI;
        area->AxisX->Maximum = 2 * PI;

        chart->ChartAreas->Add(area);

        Legend^ legend = gcnew Legend("MainLegend");
        legend->Font = gcnew Drawing::Font("Segoe UI", 9);
        legend->Docking = Docking::Top;

        chart->Legends->Add(legend);

        this->Controls->Add(lblA0);
        this->Controls->Add(txtA0);

        this->Controls->Add(lblAN);
        this->Controls->Add(txtAN);

        this->Controls->Add(lblBN);
        this->Controls->Add(txtBN);

        this->Controls->Add(lblN);
        this->Controls->Add(numHarmonics);

        this->Controls->Add(btnPlot);

        this->Controls->Add(chart);
    }


    String^ FormatCoefficient(double value)
    {
        if (Math::Abs(value) < 1e-6)
            return "";

        double absVal = Math::Abs(value);

        if (Math::Abs(absVal - 1.0) < 1e-6)
            return value < 0 ? "-" : "";

        if (Math::Abs(absVal - 0.6666667) < 0.01)
            return value < 0 ? "-2/3" : "2/3";

        if (Math::Abs(absVal - 0.5) < 0.01)
            return value < 0 ? "-1/2" : "1/2";

        return value.ToString("G");
    }


    //
    String^ FormatCoeff(double value)
    {
        double v = Math::Abs(value);

        if (Math::Abs(v - 1.0) < 1e-6)
            return "";

        if (Math::Abs(v - 0.6666667) < 0.01)
            return "2/3";

        if (Math::Abs(v - 2.0) < 1e-6)
            return "2";

        return v.ToString("F2");
    }

    // Handles the plotting process when user clicks the button
    void OnPlotClicked(Object^ sender, EventArgs^ e)
    {
        try
        {
            int N = (int)numHarmonics->Value;

            double a0 = ParseDouble(txtA0->Text);

            // Fixed plotting interval
            double xmin = -2 * PI;
            double xmax = 2 * PI;

            array<double>^ aManaged = ParseCoefficientList(txtAN->Text, N);
            array<double>^ bManaged = ParseCoefficientList(txtBN->Text, N);

            double* a = new double[N];
            double* b = new double[N];

            for (int i = 0; i < N; i++)
            {
                a[i] = aManaged[i];
                b[i] = bManaged[i];
            }

            const double T = 2.0 * PI;

            chart->Series->Clear();

            // colors used for individual harmonic components
            array<Color>^ colors = {
                Color::Red,
                Color::Green,
                Color::Purple,
                Color::Orange,
                Color::Brown,
                Color::Magenta,
                Color::DarkCyan,
                Color::Goldenrod
            };

            // create one line series per harmonic
            for (int n = 1; n <= N; n++)
            {
                String^ label = "H" + n.ToString() + " : ";

                String^ cosTerm = "";
                String^ sinTerm = "";

                double an = a[n - 1];
                double bn = b[n - 1];

                String^ aStr = FormatCoefficient(an);
                String^ bStr = FormatCoefficient(bn);

                if (aStr != "")
                {
                    if (n == 1)
                        cosTerm = aStr + "cos(t)";
                    else
                        cosTerm = aStr + "cos(" + n.ToString() + "t)";
                }

                if (bStr != "")
                {
                    String^ sinArg;

                    if (n == 1)
                        sinArg = "sin(t)";
                    else
                        sinArg = "sin(" + n.ToString() + "t)";

                    if (cosTerm != "")
                        sinTerm = (bn > 0 ? " + " : " - ") +
                        FormatCoefficient(Math::Abs(bn)) +
                        sinArg;
                    else
                        sinTerm = bStr + sinArg;
                }

                label += cosTerm + sinTerm;

                Series^ s = gcnew Series(label);
                s->ChartType = SeriesChartType::Line;
                s->BorderWidth = 2;
                s->Color = colors[(n - 1) % colors->Length];
                chart->Series->Add(s);
            }

            Series^ sumSeries = gcnew Series("f(t)");
            sumSeries->ChartType = SeriesChartType::Line;
            sumSeries->BorderWidth = 4;
            sumSeries->Color = Color::Black;
            chart->Series->Add(sumSeries);

            int samples = 1200;

            double ymin = 1e100;
            double ymax = -1e100;

            for (int i = 0; i < samples; i++)
            {
                double ratio = (double)i / (samples - 1);
                double t = xmin + (xmax - xmin) * ratio;

                double sum = a0 / 2.0;

                for (int n = 1; n <= N; n++)
                {
                    double y = Harmonic(t, n, T, a[n - 1], b[n - 1]);
                    chart->Series[n - 1]->Points->AddXY(t, y);
                    sum += y;

                    if (y < ymin) ymin = y;
                    if (y > ymax) ymax = y;
                }

                chart->Series[N]->Points->AddXY(t, sum);

                if (sum < ymin) ymin = sum;
                if (sum > ymax) ymax = sum;
            }

            ChartArea^ area = chart->ChartAreas["MainArea"];
            area->AxisX->Minimum = xmin;
            area->AxisX->Maximum = xmax;

            ConfigurePiAxis(xmin, xmax);

            if (ymin == ymax)
            {
                ymin -= 1.0;
                ymax += 1.0;
            }
            else
            {
                double margin = 0.1 * (ymax - ymin);
                ymin -= margin;
                ymax += margin;
            }

            area->AxisY->Minimum = ymin;
            area->AxisY->Maximum = ymax;



            //Generate Equation Loop
            String^ equation = "f(t) = ";
            bool firstTerm = true;

            for (int n = 1; n <= N; n++)
            {
                double an = a[n - 1];
                double bn = b[n - 1];

                if (Math::Abs(an) > 1e-6)
                {
                    if (!firstTerm && an > 0) equation += " + ";
                    if (an < 0) equation += " - ";

                    double val = Math::Abs(an);

                    if (Math::Abs(val - 1.0) > 1e-6)
                        equation += FormatCoeff(val);

                    if (n == 1)
                        equation += "cos(t)";
                    else
                        equation += "cos(" + n.ToString() + "t)";

                    firstTerm = false;
                }

                if (Math::Abs(bn) > 1e-6)
                {
                    if (!firstTerm && bn > 0) equation += " + ";
                    if (bn < 0) equation += " - ";

                    double val = Math::Abs(bn);

                    equation += FormatCoeff(val);

                    if (n == 1)
                        equation += "sin(t)";
                    else
                        equation += "sin(" + n.ToString() + "t)";

                    firstTerm = false;
                }
            }



            chart->Titles->Clear();

            Title^ title = gcnew Title(equation);
            title->Font = gcnew Drawing::Font("Segoe UI", 12, FontStyle::Bold);

            chart->Titles->Add(title);
            chart->Invalidate();

            delete[] a;
            delete[] b;
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error: " + ex->Message);
        }

    }
};

[STAThread]
int main(array<String^>^)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew FourierForm());
    return 0;
}
