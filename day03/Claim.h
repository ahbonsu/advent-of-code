#ifndef CLAIM_H_INCLUDED
#define CLAIM_H_INCLUDED


class Claim
{
    private:
        int _claim_id;
        int _x_offset;
        int _y_offset;
        int _x_length;
        int _y_length;

    public:
        Claim(int claim_id, int x_offset, int y_offset, int x_length, int y_length)
        {
            _claim_id = claim_id;
            _x_offset = x_offset;
            _y_offset = y_offset;
            _x_length = x_length;
            _y_length = y_length;
        }

        int get_claim_id()
        {
            return _claim_id;
        }

        int get_x_offset()
        {
            return _x_offset;
        }

        int get_y_offset()
        {
            return _y_offset;
        }

        int get_x_length()
        {
            return _x_length;
        }

        int get_y_length()
        {
            return _y_length;
        }

};

std::ostream& operator<<(std::ostream &os, Claim& claim)
{
    os << "id: " << claim.get_claim_id() << "; X-Offset: " << claim.get_x_offset() << "; Y-Offset: " << claim.get_y_offset() << "; X-Length: " << claim.get_x_length() << "; Y-Length: " << claim.get_y_length();
    return os;
}

#endif // CLAIM_H_INCLUDED
