#include <iostream>
#include <getopt.h>
#include <string>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::cerr;

bool brief = 0;
std::string greeting = "";
double score;
double threshold;
int digit_optind = 0;
int c;
std::string name;
unsigned int numthreads;
    
void printHelp(){
    cout << "Options:" << endl
	 << "\t--brief              Output less information" << endl
	 << "\t--greeting <string>  A greeting string" << endl
	 << "\t--score <number>     Set the score" << endl
	 << "\t--threshold <double> Set threshold" << endl
	 << "\t--numthreads <unsigned int> Set numthreads" << endl
	 << "\t--name <string>" << endl;
}

void processArgs(int argc, char **argv){
    while (1) {
        int option_index = 0;
        static struct option long_options[] = {
            {"brief",    no_argument,       nullptr, 'y' },
            {"greeting", optional_argument, nullptr, 'z' },
            {"score",    optional_argument, nullptr, 's' },
            {"threshold", optional_argument, nullptr, 'c' },
            {"name",    optional_argument, nullptr, 'n' },
            {"numthreads",    required_argument, nullptr, 't' },
            {nullptr,          0,           nullptr,  0 }
        };

	c = getopt_long(argc, argv, "", long_options, &option_index);
	if (c == -1){
	    break;
	}
	
	switch (c) {
	case 'y':
	    brief = true;
	    break;
	    
        case 'z':
	    if (optarg){
		greeting = optarg;
	    }
            break;

	case 's':
	    if (optarg){
		score = atof(optarg);
	    } else {
		cerr << "Option score specified without value." << endl;
		printHelp();
	    }
	    break;
	case 'n':
	    if (optarg){
		name = optarg;
            }
	    break;
	case 'c':
	    if (optarg){
		threshold=atof(optarg);
	    } else {
		cerr << "Option threshold specified without value." << endl;
		printHelp();
	    }
	    break;
	case 't':
	    if (optarg){
		numthreads=strtoul(optarg,nullptr,10);
	    }
	    break;

	case '?': // unrecognized option
	default:
	    printHelp();
	    exit(1);
        }
    }
}


int main (int argc, char **argv) {
    processArgs(argc, argv);

    if (brief){
	std::cout << "Flag brief is set." << endl;
    }
    cout << "greeting is: " << greeting << endl;
    cout << "score is " << score << endl;
    cout << "threshold is " << threshold <<endl;
    cout << "name is " << name << endl;
    cout << "numthreads is " << numthreads << endl;

    return 0;
}
