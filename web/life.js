/* function testcanvas(){
    var canvas = document.getElementById("life");
    var context = canvas.getContext("2d");
    context.fillStyle = "#FF0000";
    context.fillRect(0, 0, 150, 75);
} */

/* function Matrix(width, height) {
    this.width = width;
    this.height = height;
    this.pattern = [];
    this.cell = get (x, y) {
        return this.pattern[x + y * width];
    }
    this.cell = set (x, y, val) {
        if (0 <= x && x < width && 0 <= y && y < height)
            this.pattern[x + y * width] = val;
    }

    for (var i = 0; i < height; i++) {
        for (var j = 0; j < width; j++) {
            this.pattern.push(0);
        }
    }
} */

function Life(width, height, rule){
    if (rule === undefined) rule = "B3S23";
    this.width     = width;
    this.height    = height;
    this.pattern   = [];
    this.neighbors = [];
    this.born  = [0, 0, 0, 0, 0, 0, 0, 0, 0];
    this.still = [0, 0, 0, 0, 0, 0, 0, 0, 0];
    this.next = function () {
        // Count living neighbors
        for (var i = 0; i < this.height; i++) {
            for (var j = 0; j < this.width; j++) {
                if (this.pattern[i][j] == 1) {
                    var up    = (i - 1 + this.height) % this.height;
                    var down  = (i + 1 + this.height) % this.height;
                    var left  = (j - 1 + this.width ) % this.width;
                    var right = (j + 1 + this.width ) % this.width;
                    this.neighbors[up  ][left ] += 1;
                    this.neighbors[up  ][j    ] += 1;
                    this.neighbors[up  ][right] += 1;
                    this.neighbors[i   ][left ] += 1;
                    this.neighbors[i   ][right] += 1;
                    this.neighbors[down][left ] += 1;
                    this.neighbors[down][j    ] += 1;
                    this.neighbors[down][right] += 1;
                }
            }
        }
        // Updata cells' state, reset neighbors counter.
        for (var i = 0; i < this.height; i++) {
            for (var j = 0; j < this.width; j++) {
                if (this.pattern[i][j] == 1 && !this.still[this.neighbors[i][j]]) {
                    this.pattern[i][j] = 0;
                } else if (this.pattern[i][j] == 0 && this.born[this.neighbors[i][j]]) {
                    this.pattern[i][j] = 1;
                }
                this.neighbors[i][j] = 0;
            }
        }
    }

    // Parse rule "B...S..."
    var match = rule.match(/^B(\d+)S(\d+)$/);
    for (var i in match[1]) {
        this.born[Number(match[1][i])] = 1;
    }
    for (var i in match[2]) {
        this.still[Number(match[2][i])] = 1;
    }
    // Init pattern and neighbors as 2D array
    for (var i = 0; i < height; i++) {
        r1 = [];
        r2 = [];
        for (var j = 0; j < width; j++) {
            r1.push(Math.random() < 0.5 ? 0 : 1);
            r2.push(0);
        }
        this.pattern.push(r1);
        this.neighbors.push(r2);
    }
}