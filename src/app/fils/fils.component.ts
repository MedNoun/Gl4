import { Component, Input, OnInit, Output, EventEmitter } from '@angular/core';

@Component({
  selector: 'app-fils',
  templateUrl: './fils.component.html',
  styleUrls: ['./fils.component.css'],
})
export class FilsComponent implements OnInit {
  @Input('color') color: string = 'black';
  myFavoriteColor: string = 'yellow';
  @Output() colorEvent = new EventEmitter<string>();
  constructor() {}

  ngOnInit(): void {}

  onClick() {
    this.colorEvent.emit(this.myFavoriteColor);
  }
}
