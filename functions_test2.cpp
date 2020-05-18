#include "functions_test2.h"
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
                    
                    cout<<setw(30)<<left<<stud.at(i).getSurname()<<setw(30)<<left<<stud.at(i).getName()<<setw(5)<<left<<fixed<<setprecision(2)<<homeworks[(stud.at(i).getGradesCount())/2]*1.0<<"\n";
                }
                else
                {
                    cout<<setw(30)<<left<<stud.at(i).getSurname()<<setw(30)<<left<<stud.at(i).getName()<<setw(5)<<left<<fixed<<setprecision(2)<<(homeworks[(stud.at(i).getGradesCount())/2 - 1] + homeworks[((stud.at(i).getGradesCount())/2)])/2.0<<"\n";
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

void Skaityk(std::list<student> &stud, std::string filename)
{
    std::ifstream file;
    while(true){
        try{
             file.open(filename, std::ifstream::in);
            if(!file.good()) throw "Nepavyko atidaryti failo, isitikinkite, kad jis egzistuoja";
            break;
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
void Skaityk(std::deque<student> &stud, std::string filename)
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
    }
    std::sort(stud.begin(),stud.end(), sortStudents);
}

double FinalCounter(student stud)
{
    
    int sum = 0;
    double avg;

    for(int i = 0; i < stud.getGradesCount(); i++){
        sum += stud.getGrades().at(i);
    }

    avg = stud.hasGrades() ?  (double)sum/stud.getGradesCount() : 0.0;

    return (0.4 * avg) + (0.6 * stud.getExam());
}


void FinalCounter(std::deque<student> &stud)
{
    for(int i=0; i<stud.size(); i++)
    {
        int tempSum =0;
        for(int j=0; j<stud[i].getGradesCount(); j++)
        {
           tempSum+=stud.at(i).getGrades().at(j);
        }
        stud.at(i).setFinal( (tempSum*1.0/stud.at(i).getGradesCount()*0.4) + (stud.at(i).getExam())*0.6);
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
void GenerateToFile(int count, std::string outputName)
{
    std::ofstream output(outputName);

    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> dist(1, 10);
    std::uniform_int_distribution<int> countDist(7, 16);

    int poPazymiu = 10;

    output << std::setw(20) <<std::left << "Vardas";
    output << std::setw(20) <<std::left << "Pavarde";

    for(int i = 1; i <= poPazymiu; i++){
        output <<  "ND" << std::setw(4) << std::left << i;
    }

    output << "Egz.";

    for(int i = 0; i < count; i++){
        output << "\n";

        std::string vardas = "Vardas" + std::to_string(i + 1);
        std::string pavarde = "Pavarde" + std::to_string(i + 1);
        
        output << std::setw(20) << std::left << vardas;
        output << std::setw(20) << std::left << pavarde;
        for(int j = 0; j < poPazymiu + 1; j++){
            output << std::setw(6) << std::left << dist(mt);
        }
    }
    
    output.close();
}
void Generate()
{
    std::deque<double> vectorTimes, listTimes, dequeTimes;
    std::chrono::duration<double> diff;
    for(int i=1000;i<=10000000; i*=10)
    {
        std::string filename = "studentai"+std::to_string(i)+".txt";
        GenerateToFile(i, filename);

        vector<student> vectorStudents;
        std::list<student> listStudents;
        std::deque<student> dequeStudents;

        //nuskaitymas
        auto start = std::chrono::high_resolution_clock::now(); 
        Skaityk(vectorStudents, filename);
        auto end = std::chrono::high_resolution_clock::now();
        diff = end-start;
        vectorTimes.push_back(diff.count());

        start = std::chrono::high_resolution_clock::now(); 
        Skaityk(listStudents, filename);
        end = std::chrono::high_resolution_clock::now();
        diff = end-start;
        listTimes.push_back(diff.count());

        start = std::chrono::high_resolution_clock::now(); 
        Skaityk(dequeStudents, filename);
        end = std::chrono::high_resolution_clock::now();
        diff = end-start;
        dequeTimes.push_back(diff.count());

        //skaiciavimas - atskyrimas
        start = std::chrono::high_resolution_clock::now(); 
        FinalCounter(vectorStudents);
        end = std::chrono::high_resolution_clock::now();
        diff = end-start;
        vectorTimes.push_back(diff.count());

        start = std::chrono::high_resolution_clock::now(); 
        std::list<student>::iterator it = listStudents.begin();
        for(int i = 0; i < listStudents.size(); i++, it++)
        {
            (*it).setFinal(FinalCounter(*it));
        }

        end = std::chrono::high_resolution_clock::now();
        diff = end-start;
        listTimes.push_back(diff.count());

        start = std::chrono::high_resolution_clock::now(); 
        FinalCounter(dequeStudents);
        end = std::chrono::high_resolution_clock::now();
        diff = end-start;
        dequeTimes.push_back(diff.count());

        //rikiavimas
        start = std::chrono::high_resolution_clock::now(); 
        std::sort(vectorStudents.begin(), vectorStudents.end(), sortStudentsByGrade);
        end = std::chrono::high_resolution_clock::now();
        diff = end-start;
        vectorTimes.push_back(diff.count());

        start = std::chrono::high_resolution_clock::now(); 
        listStudents.sort(sortStudentsByGrade);
        end = std::chrono::high_resolution_clock::now();
        diff = end-start;
        listTimes.push_back(diff.count());

        start = std::chrono::high_resolution_clock::now(); 
        std::sort(dequeStudents.begin(), dequeStudents.end(), sortStudentsByGrade);
        end = std::chrono::high_resolution_clock::now();
        diff = end-start;
        dequeTimes.push_back(diff.count());

        //israsysimas
        /*std::string filename2 = "notcool"+std::to_string(i)+".txt";
        std::ofstream writenotCool(filename2);
        std::string filename3 = "cool"+std::to_string(i)+".txt";
        std::ofstream writeCool(filename3);
        for(int j=0;j<vectorStudents.size();j++)
        {
            if(!vectorStudents[j].cool)
            {
                 writenotCool<<std::setw(30)<<std::left<<vectorStudents[j].surname<<std::setw(30)<<std::left<<vectorStudents[j].name<<std::setw(5)<<std::left<<std::fixed<<std::setprecision(2)<<vectorStudents[j].finalGrade<<"\n";
            }
            else
            {
                writeCool<<std::setw(30)<<std::left<<vectorStudents[j].surname<<std::setw(30)<<std::left<<vectorStudents[j].name<<std::setw(5)<<std::left<<std::fixed<<std::setprecision(2)<<vectorStudents[j].finalGrade<<"\n";
            }
            
        }
        writenotCool.close();
        writeCool.close();*/

    }


        //Rezultatai

        std::cout << "---------------------------------------------------------------------\n";
        std::cout << "Skaicius        Funkcija    Su vektoriais  | Su listu  |  Su deque \n";
        std::cout << "---------------------------------------------------------------------\n";

        
        for (int i = 1000; i <= 10000000; i*=10) {
        std::cout << std::setw(15) << std::left << i << std::setw(15) << std::left << "Skaitymas" << std::setw(16) 
            << std::left << std::fixed << std::setprecision( 2 ) << vectorTimes.front()
             << std::setw(15) << std::left << std::fixed << std::setprecision( 2 ) << listTimes.front() << 
             std::fixed << std::setprecision( 2 ) << dequeTimes.front() << "\n";
        vectorTimes.pop_front();
        listTimes.pop_front();
        dequeTimes.pop_front();

        std::cout << std::setw(15) << std::left << i << std::setw(15) << std::left << "Atskyrimas" << std::setw(16) 
           << std::left << std::fixed << std::setprecision( 2 ) << vectorTimes.front()
             << std::setw(15) << std::left << std::fixed << std::setprecision( 2 ) << listTimes.front() << 
             std::fixed << std::setprecision( 2 ) << dequeTimes.front() << "\n";
        vectorTimes.pop_front();
        listTimes.pop_front();
        dequeTimes.pop_front();

        std::cout << std::setw(15) << std::left << i << std::setw(15) << std::left << "Rikiavimas" << std::setw(16) 
            << std::left << std::fixed << std::setprecision( 2 ) << vectorTimes.front()
             << std::setw(15) << std::left << std::fixed << std::setprecision( 2 ) << listTimes.front() << 
             std::fixed << std::setprecision( 2 ) << dequeTimes.front() << "\n";
        vectorTimes.pop_front();
        listTimes.pop_front();
        dequeTimes.pop_front();
        }
    
}
void Generate2()
{
    std::cout<<"Pradedami testavimai atskiriant dviem būdais. Tai gali užtrukti. \n";
    std::deque<double> vectorTimes, listTimes, dequeTimes;
    std::chrono::duration<double> diff;
    for(int i=1000;i<=10000000; i*=10)
    {
        std::string filename = "studentai"+std::to_string(i)+".txt";
        GenerateToFile(i, filename);

        vector<student> vectorStudents;
        std::list<student> listStudents;
        std::deque<student> dequeStudents;

        //nuskaitymas
        Skaityk(vectorStudents, filename);

        Skaityk(listStudents, filename);

        Skaityk(dequeStudents, filename);

         //skaiciavimas
        FinalCounter(vectorStudents);
 
        std::list<student>::iterator it = listStudents.begin();
        for(int i = 0; i < listStudents.size(); i++, it++)
        {
            (*it).setFinal(FinalCounter(*it));
        }

        FinalCounter(dequeStudents);

        //Atskyrimas 1 būdu
        vector<student> vectorKietiakai, vectorLievakai;
        std::list<student> listKietiakai, listLievakai;
        std::deque<student> dequeKietiakai, dequeLievakai;

        // su vektoriumi
        auto start = std::chrono::high_resolution_clock::now(); 
        for(int j = 0; j < i; j++) {
            if(vectorStudents.at(j).getFinal() >= 5) {
                vectorKietiakai.push_back(vectorStudents.at(j));
            }
            else vectorLievakai.push_back(vectorStudents.at(j));
        }
        auto end = std::chrono::high_resolution_clock::now();
        diff = end-start;
        vectorTimes.push_back(diff.count());

        vectorKietiakai.clear();
        vectorLievakai.clear();

        // su listu
        it = listStudents.begin();

        start = std::chrono::high_resolution_clock::now(); 
        for(int j = 0; j < i; j++, it++) {
            if((*it).getFinal() >= 5) listKietiakai.push_back((*it));
            else listLievakai.push_back((*it));
        }
        end = std::chrono::high_resolution_clock::now();
        diff = end-start;
        listTimes.push_back(diff.count());

        listKietiakai.clear();
        listLievakai.clear();

        // su deque
        start = std::chrono::high_resolution_clock::now();
        for(student &s: dequeStudents) {
            if(s.getFinal() >= 5) {
                dequeKietiakai.push_back(s);
            }
            else dequeLievakai.push_back(s);
        }
        end = std::chrono::high_resolution_clock::now();
        diff = end-start;
        dequeTimes.push_back(diff.count());

        dequeKietiakai.clear();
        dequeLievakai.clear();


        //Atskyrimas antruoju būdu
/*
        //su vektoriumi
        start = std::chrono::high_resolution_clock::now();

        vectorKietiakai.resize(vectorStudents.size());
        auto cpyIt = std::copy_if(
            vectorStudents.begin(), 
            vectorStudents.end(), 
            vectorKietiakai.begin(),
            [](student s){return s.getExam() >= 5;});
        vectorKietiakai.resize(std::distance(vectorKietiakai.begin(), cpyIt));

        vectorStudents.erase(
            std::remove_if(
                vectorStudents.begin(), 
                vectorStudents.end(), 
                [](student s){return s.getExam() >= 5;}
            ),
            vectorStudents.end()
        );
        end = std::chrono::high_resolution_clock::now();
        diff = end-start;
        vectorTimes.push_back(diff.count());

        vectorKietiakai.clear();
        vectorLievakai.clear();

        // su listu
        start = std::chrono::high_resolution_clock::now();       
        for(student &s: listStudents) {
            if(s.getFinal() >= 5) listKietiakai.push_back(s);
        }
        listStudents.remove_if([](student s){return s.getFinal() >= 5;});
        end = std::chrono::high_resolution_clock::now();
        diff = end-start;
        listTimes.push_back(diff.count());

        listKietiakai.clear();
        listLievakai.clear();

        // su deque
        start = std::chrono::high_resolution_clock::now();  
        for(student &s: dequeStudents) {
            if(s.getFinal() >= 5) dequeKietiakai.push_back(s);
        }
        dequeStudents.erase(
            std::remove_if(
                dequeStudents.begin(),
                dequeStudents.end(),
                [](student s){return s.getExam() >= 5;}
            ),
            dequeStudents.end()
        );
        end = std::chrono::high_resolution_clock::now();
        diff = end-start;
        dequeTimes.push_back(diff.count());

        dequeKietiakai.clear();
        dequeLievakai.clear();
        */
    }
    // Isvedami rezultatai
    std::cout << "----------------------------------------------------------------------------------------- \n";
    std::cout << "Skaicius        Funkcija           Laikas su vector | Laikas su listu | Laikas su deque   \n";
    std::cout << "----------------------------------------------------------------------------------------- \n";

    for (int i = 1000; i <= 10000000; i*=10) {
        std::cout << std::setw(13) << std::left << i << std::setw(25) << std::left << "Pirmu budu atskirti" << std::setw(16) 
            << std::left << std::setprecision(4) << std::fixed << vectorTimes.front() << std::setw(25) << std::left 
            << std::setprecision(4) << std::fixed << listTimes.front() << std::setprecision(4) << std::fixed << dequeTimes.front() << "\n";
        vectorTimes.pop_front();
        listTimes.pop_front();
        dequeTimes.pop_front();
    }

}
