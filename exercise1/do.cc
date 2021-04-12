#include <iostream>
#include <getopt.h>
#include <string>

using std::cout;
using std::endl;
using std::cerr;

bool brief = 0;
std::string greeting = "";
std::string name = "";
double score;
int digit_optind = 0;
int c;
unsigned int numthreads;
double threshold;
int x_offset;

void printHelp(){
    cout << "Options:" << endl
	 << "\t--brief              Output less information" << endl
	 << "\t--greeting <string>  A greeting string" << endl
	 << "\t--score <number>     Set the score" << endl
   << "\t--name <string>      Set the name" << endl
	 << "\t--numthreads <unsigned integer>  Set numthreads" << endl
	 << "\t--threshold <number>     Set the threshold" << endl
	 << "\t--x-offset <number>  Set the x-offset" << endl;
}

void processArgs(int argc, char **argv){
    while (1) {
        int option_index = 0;
        static struct option long_options[] = {
            {"brief",    no_argument,       nullptr, 'y' },
            {"greeting", optional_argument, nullptr, 'z' },
            {"score",    optional_argument, nullptr, 's' },
            {"numthreads",   optional_argument, nullptr, 'a' },
            {"threshold",    optional_argument, nullptr, 'c' },
            {"name", optional_argument, nullptr, 'w'  },
            {"x-offset", optional_argument, nullptr, 'd' },
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

	case 'w':
            if (optarg){
                name = optarg;
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

	case 'a':
	    if (optarg){
		numthreads = strtoul(optarg, nullptr, 10);
	    } else {
		cerr << "Option numthreads specified without value." << endl;
		printHelp();
	    }
	    break;

	case 'c':
	    if (optarg){
		threshold = atof(optarg);
	    } else {
		cerr << "Option threshold specified without value." << endl;
		printHelp();
	    }
	    break;

	case 'd':
	    if (optarg){
	        x_offset = atoi(optarg);
	    } else {
	        cerr << "Option x-offset specified without value." << endl;
	        printHelp();
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
    cout << "numthreads is " << numthreads << endl;
    cout << "threshold is " << threshold << endl;
    cout << "name is: " << name << endl;
    cout << "x-offset is " << x_offset << endl;

    return 0;
}
