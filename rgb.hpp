struct Rgb{
    double 
        red,
        green,
        blue;
    bool activia;

    bool equals(struct Rgb color) {
        return color.red == red && color.green == green && color.blue == blue;
    }
};

const Rgb 
    RED = {1.0, 0.0, 0.0, false},
    GREEN = {0.0, 1.0, 0.0, false},
    BLUE = {0.0, 0.0, 1.0, false},
    WHITE = {1.0, 1.0, 1.0, false},
    BLACK = {0.0, 0.0, 0.0, false};