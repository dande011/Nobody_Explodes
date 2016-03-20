get current time

go to current date/time in file

look for "[BombGenerator] Generator settings: Time: 300, NumStrikes: 3"
set variable time
send time variable to arduino

look for "DEBUG 2016-03-20 07:53:27,940 [Assets.Scripts.Pacing.PaceMaker] Round start! Mission: The First Bomb Pacing Enabled: False"
tell arduino to start countdown

look for " INFO 2016-03-20 07:38:16,121 [Bomb] Boom"
tell arduino to blow up bomb

get new time for next game


