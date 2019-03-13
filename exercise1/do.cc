#include <iostream>
#include <getopt.h>
#include <string>

using std::cout;
using std::endl;
using std::cerr;

bool brief = 0;
std::string greeting = "";
double score;
int digit_optind = 0;
int c;
unsigned num_thread;

void printHelp(){
    cout << "Options:" << endl
	 << "\t--brief                  Output less information" << endl
	 << "\t--greeting <string>      A greeting string" << endl
	 << "\t--score <number>         Set the score" << endl
	 << "\t--num_thread <number>    Number of threads to use" << endl;
}

void processArgs(int argc, char **argv){
    while (1) {
        int option_index = 0;
        static struct option long_options[] = {
            {"brief",    no_argument,       nullptr, 'y' },
            {"greeting", optional_argument, nullptr, 'z' },
            {"score",    optional_argument, nullptr, 's' },
            {"num_thread",    optional_argument, nullptr, 'n' },
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
		num_thread = atoi(optarg);
	    } else {
		cerr << "Option num_thread specified without value." << endl;
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
    cout << "num_thread is " << num_thread << endl;

    return 0;
}
