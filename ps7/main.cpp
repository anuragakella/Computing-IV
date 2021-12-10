// Copyright 2021 Anurag Akella
#include <iostream>
#include <string>
#include <fstream>
#include <boost/regex.hpp>
#include "boost/date_time/posix_time/posix_time.hpp"


using std::cout;
using std::cin;
using std::endl;
using std::string;
using boost::regex;
using boost::smatch;
using boost::regex_error;
using boost::gregorian::date;
using boost::gregorian::from_simple_string;
using boost::gregorian::date_period;
using boost::gregorian::date_duration;
using boost::posix_time::ptime;
using boost::posix_time::time_duration;


int main(int argc, char **args) {
    if (argc != 2) {
        cout << "usage: ./ps7 [logfile]" << endl;
        exit(1);
    }
    string sgx, rs;
    regex start_rgx;
    regex succ_rgx;
    bool flag = false;
    ptime t1, t2;
    string filename(args[1]);
    std::ifstream infile(filename);
    std::ofstream outfile(filename + ".rpt");
    if (!infile || !outfile) {
        cout << "open file error" << endl;
        exit(1);
    }
    try {
        start_rgx = regex(R"((.*): (\(log.c.166\) server started.*))");
        succ_rgx = regex("(.*)\\.\\d*:INFO:oejs.AbstractConnector:Started "
                   "SelectChannelConnector@0.0.0.0:9080.*");
    }
    catch (regex_error &exc) {
        // lambda
        [&]() {
            cout << "regex init failed" << exc.code() << endl;
        }();
        exit(1);
    }
    int line_number = 1;
    string stx;
    while (getline(infile, sgx)) {
        if (regex_match(sgx, start_rgx)) {
            smatch sm;
            regex_match(sgx, sm, start_rgx);
            if (flag) outfile << "failure" << endl;
            flag = true;
            t1 = ptime(boost::posix_time::time_from_string(sm[1]));
            stx = sm[2];
            outfile << line_number << " (log.c.166) server started "
                    << sm[1] << " ";
        }
        if (regex_match(sgx, succ_rgx)) {
            smatch sm;
            regex_match(sgx, sm, succ_rgx);
            t2 = ptime(boost::posix_time::time_from_string(sm[1]));
            outfile << "success " << (t2 - t1).total_milliseconds()
                    << "ms" << endl;
            flag = false;
        }
        line_number++;
    }
    if (flag) outfile << "failure" << endl;
    infile.close();
    outfile.close();
    return 0;
}
