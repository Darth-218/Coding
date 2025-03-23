class Walker {

  constructor() {
    this.x = width / 2;
    this.y = height / 2;
    this.map = [];
  }

  show() {
    stroke(0);
    point(this.x, this.y);
  }

  validate(x, y) {
    if (this.map.includes([x, y])) {
      return false;
    }
    console.log("Valid");
    map.push([x, y]);
    return true;
  }

  step() {
    let choice = floor(random(4));

    if (choice === 0) {
      if (this.validate(this.x + 1, this.y)) {
	this.x++;
      }
    } else if (choice === 1) {
      if (this.validate(this.x - 1, this.y)) {
	this.x--;
      }
    } else if (choice === 2) {
      if (this.validate(this.x, this.y + 1)) {
	this.y++;
      }
    } else {
      if (this.validate(this.x, this.y - 1)) {
	this.y--;
      }
    }
  }
}

let walker;

function setup() {
  createCanvas(840, 640);
  walker = new Walker();
  background(134);
}

function draw() {
  walker.show();
  walker.step();
}
