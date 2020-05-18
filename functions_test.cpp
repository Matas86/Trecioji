#include "functions_test.h"
#include "vector.h"

#include <iostream>
#include <iomanip>
#include <chrono>

student& student::operator=(const student& studd)
{
    name = studd.name;
    surname = studd.surname;
    homework = studd.homework;
    exam = studd.exam;
    finalGrade = studd.finalGrade;
    random = studd.random;
    return *this;
}

student::student(std::string studentData)
{
    int p;
    std::string p1;
    std::stringstream stream;
    stream<<studentData;
    stream>>name>>surname;
    while(stream>>p1)
    {
        p = stoi(p1);
        homework.push_back(p);
    }
    exam = homework.back();
    homework.pop_back();
}

student::student(std::string n, std::string s)
{
    name = n;
    surname = s;
}

student::~student()
{
    homework.clear();
    homework.shrink_to_fit();
}

void check()
{
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"\n";
}

void StartProgram()
{
    srand(time(NULL));

    std::string failas;
    std::cout<<"Ar duomenys bus nuskaitomi is duomenu failo? (taip - y, ne - n) \n";
    std::cin>>failas;
    if(failas == "y")
    {
        std::cout<<"Iveskite duomenu failo pavadinima: \n";
        while(!(std::cin >> failas))
        {
        std::cout << "Bloga ivestis! Iveskite savo failo pavadinima";
        check();
        }

        vector<student> stud;
        stud.reserve(100000);
        Skaityk(stud,failas);
        Isvesk(stud);
    }
    else
    {
        int N;

        std::cout<<"Iveskite studentu skaiciu: \n";
        while(!(std::cin >> N) || N<0)
        {
            std::cout << "Bloga ivestis! Iveskite studentu skaiciu skaitmeniu";
            check();
        }

        vector<student> stud;
        stud.reserve(100000);
        std::string randomas;
        for(int i=0; i<N; i++)
        {
            std::cout<<"Ar norite, kad studento pazymiai butu generuojami atsitiktinai? (taip - y, ne - n)"<<std::endl;
            while(!(std::cin >> randomas))
            {
                std::cout << "Bloga ivestis! Iveskite raidę y arba n";
                check();
            }
            if(randomas == "y")
                stud[i].setRandom(true);
            else
                stud[i].setRandom(false);

            if(!stud[i].getRandom())
        {
            
            std::string name, surname;
            std::cout<<"Iveskite savo varda: \n";
            while(!(std::cin >> name))
            {
                std::cout << "Bloga ivestis! Iveskite savo varda";
                check();
            }

            std::cout<<"Iveskite savo pavarde: \n";
            while(!(std::cin >> surname))
            {
                std::cout << "Bloga ivestis! Iveskite savo pavarde";
                check();
            }
            student currentStud(name,surname);
            int skc;
            bool veda;
            std::string ats;
            skc = 0;
            veda = true;
            int skaicius;
            while(veda)
            {
                std::cout<<"Iveskite savo " << currentStud.getGradesCount()+1 << " namu darbu bala: \n";

                while(!(std::cin >> skaicius && skaicius<=10 && skaicius>=0))
                {
                    std::cout << "Bloga ivestis! Iveskite savo namu darbu bala skaiciumi (0-10)";
                    check();
                }
                currentStud.addGrade(skaicius);
                std::cout<<"Ar norite toliau vesti namu darbu balus? (taip - y, ne - n) \n";
                std::cin>>ats;
                if(ats == "n")
                {
                    veda=false;
                }
                
            }



            std::cout<<"Iveskite savo egzamino bala: \n";
            int examGrade;
            while(!(std::cin >> examGrade) && examGrade <= 10 && examGrade >= 0 )
            {
                std::cout << "Bloga ivestis! Iveskite savo egzamino bala skaiciumi (0-10)";
                check();
            }
            currentStud.setExam(examGrade);
            stud.push_back(currentStud);
        }
        else
        {
            std::string name, surname;
            std::cout<<"Iveskite savo varda: \n";
            while(!(std::cin >> name))
            {
                std::cout << "Bloga ivestis! Iveskite savo varda";
                check();
            }

            std::cout<<"Iveskite savo pavarde: \n";
            while(!(std::cin >> surname))
            {
                std::cout << "Bloga ivestis! Iveskite savo pavarde";
                check();
            }
            student currentStud(name,surname); 
        int skc;
        bool veda;
        std::string ats;
        skc = 0;
        veda = true;
        int skaicius;
        while(veda)
        {
            std::cout<<"Sugeneruotas " << skc+1 << " namu darbu balas: \n";
            skaicius = rand() %10 +1;
            std::cout<<skaicius<<std::endl;
            skc++;
            currentStud.addGrade(skaicius);
            std::cout<<"Ar norite toliau generuoti namu darbu balus? (taip - y, ne - n) \n";
            std::cin>>ats;
            if(ats == "n")
            {
                veda=false;
            }
        }



        std::cout<<"Sugeneruotas egzamino balas: \n";
        currentStud.setExam(rand()%10 +1);
        std::cout<<currentStud.getExam()<<std::endl;
        stud.push_back(currentStud);
        }
            

        }
        Isvesk(stud);
    }
}

void Isvesk(vector<student> stud)
{
    using namespace std;
    FinalCounter(stud);
    string ats;
    cout<<"Norite isvesti atsakymus i komandine eilute ar i tekstini faila? (cmd - komandine eilute, file - tekstinis failas) \n";
    cin>>ats;
    if(ats=="cmd")
    {
        cout<<"Norite gauti vidurki ar mediana? (Vidurkis - v, Mediana - m) \n";
        string temp;
        cin>>temp;
        
        if(temp == "v")
        {
            cout<<setw(30)<<left<<"Pavarde"<<setw(30)<<left<<"Vardas"<<setw(5)<<"Galutinis (Vid.)"<<endl;
            cout<<"------------------------------------------------------------------------"<<endl;


            for(int i=0; i<stud.size(); i++)

                cout<<setw(30)<<left<<stud[i].getSurname()<<setw(30)<<left<<stud[i].getName()<<setw(5)<<left<<fixed<<setprecision(2)<<stud[i].getFinal()<<"\n";
        }

        else if( temp == "m")
        {
            cout<<setw(30)<<left<<"Pavarde"<<setw(30)<<left<<"Vardas"<<setw(5)<<"Galutinis (Med.)"<<endl;
            cout<<"------------------------------------------------------------------------"<<endl;

            for(int i=0; i<stud.size(); i++)
            {

                sort(stud.begin(), stud.end(), sortStudents);

                vector<int> homeworks = stud[i].getGrades();
                if(stud[i].getGradesCount()%2==1)
                {
                    
                    cout<<setw(30)<<left<<stud[i].getSurname()<<setw(30)<<left<<stud[i].getName()<<setw(5)<<left<<fixed<<setprecision(2)<<homeworks[(stud[i].getGradesCount())/2]*1.0<<"\n";
                }
                else
                {
                    cout<<setw(30)<<left<<stud[i].getSurname()<<setw(30)<<left<<stud[i].getName()<<setw(5)<<left<<fixed<<setprecision(2)<<(homeworks[(stud[i].getGradesCount())/2 - 1] + homeworks[((stud[i].getGradesCount())/2)])/2.0<<"\n";
                }

            }
        }
        else
        {
            cout<<"Bloga įvestis. \n";
        }
    }
    else
    {
        ofstream write("atsakymai.txt");
        cout<<"Norite gauti vidurki ar mediana? (Vidurkis - v, Mediana - m) \n";
        string temp;

        cin>>temp;
        if(temp == "v")
        {
            write<<setw(30)<<left<<"Pavarde"<<setw(30)<<left<<"Vardas"<<setw(5)<<"Galutinis (Vid.)"<<endl;
            write<<"------------------------------------------------------------------------"<<endl;


            for(int i=0; i<stud.size(); i++)

                write<<setw(30)<<left<<stud[i].getSurname()<<setw(30)<<left<<stud[i].getName()<<setw(5)<<left<<fixed<<setprecision(2)<<stud[i].getFinal()<<"\n";
        }

        else if( temp == "m")
        {
            write<<setw(30)<<left<<"Pavarde"<<setw(30)<<left<<"Vardas"<<setw(5)<<"Galutinis (Med.)"<<endl;
            write<<"-------------------------------------------------------------------------"<<endl;

            for(int i=0; i<stud.size(); i++)
            {

                sort(stud.begin(), stud.end(), sortStudents);

                vector<int> homeworks = stud[i].getGrades();

                if(stud[i].getGradesCount()%2==1)
                {

                    write<<setw(30)<<left<<stud[i].getSurname()<<setw(30)<<left<<stud[i].getName()<<setw(5)<<left<<fixed<<setprecision(2)<<homeworks[(stud[i].getGradesCount())/2]*1.0<<"\n";
                }
                else
                {
                    write<<setw(30)<<left<<stud[i].getSurname()<<setw(30)<<left<<stud[i].getName()<<setw(5)<<left<<fixed<<setprecision(2)<<(homeworks[(stud[i].getGradesCount())/2 - 1] + homeworks[((stud[i].getGradesCount())/2)])/2.0<<"\n";
                }

            }
        }
        else
        {
            cout<<"Bloga įvestis. \n";
        }
    }

}

void Skaityk(vector<student> &stud, std::string filename)
{
    std::ifstream file;
    while(true){
        try{
             file.open(filename, std::ifstream::in);
            if(!file.good()) throw "Nepavyko atidaryti failo, isitikinkite, kad jis egzistuoja";
            break;
        }catch(const char * e){
            std::cout << e << "\n";
        }
    }    
    std::string line;
    std::ifstream read(filename);
    std::getline(read,line);
    std::string pazymysSt;
    int pazInt;
    
    while(getline(read,line))
    {
        std::stringstream stream;
        std::string name,surname;
        stream<<line;
        stream>>name>>surname;
        student *currentStud = new student(name,surname);
        while(stream>>pazymysSt)
        {
            try
            {
                pazInt = stoi(pazymysSt);
            }
            catch(const std::exception& e)
            {
                std::cout<<"Ivyko klaida nuskaitant pazymi \n";
            }
            
            currentStud->addGrade(pazInt);
        }

        currentStud->setExam(pazInt);
        currentStud->getGrades().pop_back();
        stud.push_back(*currentStud);
        delete currentStud;

    }
    file.close();
}


void FinalCounter(vector<student> &stud)
{
    for(int i=0; i<stud.size(); i++)
    {
        int tempSum =0;
        for(int j=0; j<stud[i].getGradesCount(); j++)
        {
           tempSum+=stud.at(i).getGrades().at(j);
        }
        stud.at(i).setFinal( (tempSum*1.0/stud.at(i).getGradesCount()*0.4) + (stud.at(i).getExam())*0.6);
        if(stud.at(i).getFinal() >= 5) 
            {
                stud.at(i).setCool(true);
                //cout<<"COOL id: " <<i<<" "<<stud.at(i).getFinal() <<std::endl;
            }
        else 
            {
                stud.at(i).setCool(false);
                //cout<<"NOT COOL id: " <<i<<std::endl;
                //cout<<stud.at(i).getFinal()<<std::endl;
            }
    }
    std::sort(stud.begin(),stud.end(), sortStudents);
}

bool sortStudents(student A, student B)
{
    if(B.getName() > A.getName() || B.getSurname() > A.getSurname() )
    {
        return true;
    }
    return false;
}

bool sortStudentsByGrade(student A, student B)
{
    if(B.getFinal() > A.getFinal())
    {
        return true;
    }
    return false;
}

void Generate(int n)
{
    auto startFull = std::chrono::high_resolution_clock::now(); 
    vector<student> Students;
    Students.reserve(n);
    std::string filename = "studentai"+std::to_string(n)+".txt";
    std::cout<<"Pradedama dirbti su "<<std::to_string(n)<<" studentu duomenu failu\n";
    auto start = std::chrono::high_resolution_clock::now(); 
    std::ofstream write(filename);
    write<<std::setw(30)<<std::left<<"Pavarde"<<std::setw(30)<<std::left<<"Vardas";
    for(int j=0;j<10;j++, write<<std::setw(5)<<std::left<<"ND"+std::to_string(j));
    write<<std::setw(5)<<std::left<<"Exam"<<std::endl;

    for(int i=0;i<n;i++)
    {
        write<<std::setw(30)<<std::left<<"pavarde"+std::to_string(i);
        write<<std::setw(30)<<std::left<<"vardas"+std::to_string(i);

        for(int j=0;j<10;j++)
        {
            write<<std::setw(5)<<rand() %10 +1;
        }

        write<<std::setw(5)<<rand() %10 +1<<std::endl;
    }
    write.close();
    auto end = std::chrono::high_resolution_clock::now(); 
    std::chrono::duration<double> diff = end-start;
    std::cout<<"Failas sugeneruotas per: "<<std::fixed<<std::setprecision(2)<<diff.count()<<"s"<<std::endl;

    start = std::chrono::high_resolution_clock::now(); 
    Skaityk(Students,filename);
    end = std::chrono::high_resolution_clock::now(); 
    diff = end-start;
    std::cout<<"Failas perskaitytas per: "<<std::fixed<<std::setprecision(2)<<diff.count()<<"s"<<std::endl;

    start = std::chrono::high_resolution_clock::now(); 
    FinalCounter(Students);
    end = std::chrono::high_resolution_clock::now();
    diff = end-start;
    std::cout<<"Studentai atskirti i dvi grupes per: "<<std::fixed<<std::setprecision(2)<<diff.count()<<"s"<<std::endl;

    start = std::chrono::high_resolution_clock::now(); 
    std::sort(Students.begin(),Students.end(), sortStudentsByGrade);
    end = std::chrono::high_resolution_clock::now();
    diff = end-start;
    std::cout<<"Studentai didejimo tvarka surusiuoti per: "<<std::fixed<<std::setprecision(2)<<diff.count()<<"s"<<std::endl;

    start = std::chrono::high_resolution_clock::now(); 
    std::string filename2 = "notcool"+std::to_string(n)+".txt";
    std::ofstream writenotCool(filename2);
    for(int i=0;i<Students.size();i++)
    {
        if(Students.at(i).getFinal() < 5)
        {
            //cout<<Students.at(i).getFinal()<<" "<< Students.at(i).getCool()<<std::endl;
            writenotCool<<std::setw(30)<<std::left<<Students[i].getSurname()<<std::setw(30)<<std::left<<Students[i].getName()<<std::setw(5)<<std::left<<std::fixed<<std::setprecision(2)<<Students[i].getFinal()<<"\n";
        }
    }
    writenotCool.close();
    end = std::chrono::high_resolution_clock::now();
    diff = end-start;
    std::cout<<"Studentai, kuriu vidurkis zemesnis 5, irasyti per: "<<std::fixed<<std::setprecision(2)<<diff.count()<<"s"<<std::endl;

    start = std::chrono::high_resolution_clock::now(); 
    std::string filename3 = "cool"+std::to_string(n)+".txt";
    std::ofstream writeCool(filename3);
    for(int i=0;i<Students.size();i++)
    {
        if(Students.at(i).getFinal() >= 5)
        {
            writeCool<<std::setw(30)<<std::left<<Students[i].getSurname()<<std::setw(30)<<std::left<<Students[i].getName()<<std::setw(5)<<std::left<<std::fixed<<std::setprecision(2)<<Students[i].getFinal()<<"\n";
        }
    }
    writeCool.close();
    end = std::chrono::high_resolution_clock::now();
    diff = end-start;
    std::cout<<"Studentai, kuriu vidurkis auksciau arba lygu 5, irasyti per: "<<std::fixed<<std::setprecision(2)<<diff.count()<<"s"<<std::endl;

    auto endFull = std::chrono::high_resolution_clock::now(); 
    diff = endFull-startFull;
    std::cout<< "Is viso " << n << " irasu testas padarytas per: " << std::fixed<<std::setprecision(2)<< diff.count() << "s\n";
    std::cout<<"Spauskite enter, norint pereiti prie kito testo generavimo \n";
    std::cin.ignore(256, '\n');
    std::cin.get();
}
