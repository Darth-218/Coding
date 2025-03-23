document.getElementById('noButton').addEventListener('mouseover', function() {
    const button = this;
    const buttonWidth = button.clientWidth;
    const buttonHeight = button.clientHeight;

    const maxX = window.innerWidth - buttonWidth;
    const maxY = window.innerHeight - buttonHeight;

    const x = Math.random() * maxX / 2;
    const y = Math.random() * maxY / 2;

    button.style.position = 'absolute';
    button.style.transition = 'left 0.1s, top 0.1s';
    button.style.left = `${Math.min(x, maxX)}px`;
    button.style.top = `${Math.min(y, maxY)}px`;
});

document.getElementById('noButton').addEventListener('click', function() {
    const button = this;
    button.style.position = 'absolute';
    button.style.left = `10px`;
    button.style.top = `10px`;
    button.style.transition = 'left 0.1s, top 0.1s';
});

document.getElementById('yesButton').addEventListener('click', function() {
    window.location.href = "p.html";
});

const colors = ["#F2003C", "#FF6EC7", "#DE3163"];
const SVG_NS = 'http://www.w3.org/2000/svg';
const SVG_XLINK = "http://www.w3.org/1999/xlink";

let heartsRy = []

function useTheHeart(n){
  let use = document.createElementNS(SVG_NS, 'use');
  use.n = n;
  use.setAttributeNS(SVG_XLINK, 'xlink:href', '#heart');
  use.setAttributeNS(null, 'transform', `scale(${use.n})`);
  use.setAttributeNS(null, 'fill', colors[n%colors.length]);
  use.setAttributeNS(null, 'x', -69);
  use.setAttributeNS(null, 'y', -69);
  use.setAttributeNS(null, 'width', 138);
  use.setAttributeNS(null, 'height', 138);
  
  heartsRy.push(use)
  hearts.appendChild(use);
}

for(let n = 18; n >= 0; n--){useTheHeart(n)}

function Frame(){
  window.requestAnimationFrame(Frame);
  for(let i = 0; i < heartsRy.length; i++){
    if(heartsRy[i].n < 18){heartsRy[i].n +=.05
     }else{
     heartsRy[i].n = 0;
     hearts.appendChild(heartsRy[i])
    }
    heartsRy[i].setAttributeNS(null, 'transform', `scale(${heartsRy[i].n})`);
  }
}

Frame()

