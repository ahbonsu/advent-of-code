#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Claim.h"

#include <boost/algorithm/string.hpp>

void update_max(int& current_max, int val)
{
    if(val > current_max)
    {
        current_max = val;
    }
}

// this

int main()
{
    std::fstream file("input");
    std::vector<std::string> input;

    std::string line;
    while (std::getline(file, line))
    {
        input.push_back(line);
    }

    std::vector<Claim> claims;

    for(size_t i = 0; i < input.size(); i++)
    {
        std::vector<std::string> parts;

        boost::split(parts, input[i], boost::is_space());

        int id(std::stoi(parts[0].substr(1)));

        std::string offset = parts[2];
        std::vector<std::string> offset_parts;
        boost::split(offset_parts, offset, boost::is_any_of(","));

        int x_offset = std::stoi(offset_parts[0]);
        int y_offset = std::stoi(offset_parts[1]);

        std::string rectangle_dimensions = parts[3];
        std::vector<std::string> dimensions_parts;
        boost::split(dimensions_parts, rectangle_dimensions, boost::is_any_of("x"));

        int x_length = std::stoi(dimensions_parts[0]);
        int y_length = std::stoi(dimensions_parts[1]);

        Claim c(id, x_offset, y_offset, x_length, y_length);
        claims.push_back(c);
    }

    //dimensions for matrix
    int x_max = 0;
    int y_max = 0;

    for(size_t i = 0; i < claims.size(); i++)
    {
        update_max(x_max, claims[i].get_x_offset() + claims[i].get_x_length());
        update_max(y_max, claims[i].get_y_offset() + claims[i].get_y_length());
    }


    int overlap_count = 0;

    int matrix [x_max][y_max];

    for(size_t i = 0; i < claims.size(); i++)
    {
        for(int x = 0; x < claims[i].get_x_length(); x++)
        {
            for(int y = 0; y < claims[i].get_y_length(); y++)
            {
                int x_abs = claims[i].get_x_offset() + x;
                int y_abs = claims[i].get_y_offset() + y;

                int current = matrix[x_abs][y_abs];
                if(current == 0)
                {
                    matrix[x_abs][y_abs] = 1;
                }
                else
                {
                    if(current == 1)
                    {
                        overlap_count += 1;
                        matrix[x_abs][y_abs] = 2;
                    }
                    else
                    {
                        matrix[x_abs][y_abs] = current + 1;
                    }
                }
            }
        }
    }

    std::cout << "overlaps: " << overlap_count << std::endl;


    for(size_t i = 0; i < claims.size(); i++)
    {
        bool overlapped = false;
        for(int x = 0; x < claims[i].get_x_length(); x++)
        {
            for(int y = 0; y < claims[i].get_y_length(); y++)
            {
                int x_abs = claims[i].get_x_offset() + x;
                int y_abs = claims[i].get_y_offset() + y;

                int current = matrix[x_abs][y_abs];

                if(current > 1)
                {
                    overlapped = true;
                }
            }
        }

        if(overlapped != true)
        {
            std::cout << "ID: " << claims[i].get_claim_id() << std::endl;
        }
    }


    return 0;
}
