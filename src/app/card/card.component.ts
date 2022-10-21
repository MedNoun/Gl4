import { Component, OnInit } from '@angular/core';

interface person {
  name?: string;
  first_name?: string;
  job?: string;
  image?: string;
  citation?: string;
  description?: string;
  mot_cle?: string;
}

@Component({
  selector: 'app-card',
  templateUrl: './card.component.html',
  styleUrls: ['./card.component.css'],
})
export class CardComponent implements OnInit {
  public info: person;
  constructor() {
    this.info = {
      name: 'Hammami',
      first_name: 'Slim',
      job: 'Valorant',
      citation: 'Nheb il barca',
      description: 'Ena nheb barcha barcha il tarajji',
      mot_cle: 'hoes, bros, fk, harder, stronger, everyday',
    };
    console.log(this.info);
  }

  ngOnInit(): void {}
}
