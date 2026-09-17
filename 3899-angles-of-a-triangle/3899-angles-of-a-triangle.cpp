class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        
        sort(sides.begin(), sides.end());

        int a = sides[0];
        int b = sides[1];
        int c = sides[2];

        // Check if triangle is valid
        if (a + b <= c) {
            return {};
        }

        // Law of Cosines
        double A = acos(
            (1.0 * b * b + 1.0 * c * c - 1.0 * a * a)
            / (2.0 * b * c)
        ) * 180.0 / acos(-1.0);

        double B = acos(
            (1.0 * a * a + 1.0 * c * c - 1.0 * b * b)
            / (2.0 * a * c)
        ) * 180.0 / acos(-1.0);

        double C = 180.0 - A - B;

        return {A, B, C};
    }
};