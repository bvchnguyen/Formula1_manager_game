# Formula1 Manager Game

A turn-based game inspired by the role of a racer's personal engineer in the racing sport Formula 1.

## Background:

Formula 1 racing is much more than “pedal to the medal”. To win, it takes a team of dedicated engineers and strategists to determine the best variables so that their driver comes out on top on race weekends.

A formula 1 driver will have a dedicated engineer. This person is in direct communication to the driver during the race to provide him the information he needs, such as his lap-times, fuel data, tyre wear, etc.

For the very last race weekend, you’ve been tasked by Scuderia Ferrari F1 Team to be a substitute for Sebastian Vettel’s race engineer due to his primary one having to quarantine because of covid. Vettel is up 16 points from runner up to Lewis Hamilton, and would only need to secure a 5th place finish to be able to win the Driver’s World Championship. 

## Setbacks:

Unfortunately for this weekend, Vettel had to take a 10 place grid penalty as he needed his engine to be replaced. Vettel qualified on pole (1st) during Saturday qualifying session, which would mean that he will start in 11th place after the grid penalty is applied.

It is anticipated that Hamilton will be dominant with Vettel out of the front running equation, which means that he will most likely win the race and score 25 points. 

## Objective: 

Your task is to make sure that Vettel finishes 5th place or higher (score at least 10 points) to be able to secure the Championship. To do so, the team has predicted that if Vettel can at least finish the 70 lap race in 140 minutes, he will finish in 5th place.

## Point System:

![](https://www.tutorialspoint.com/formula_one/images/championship_points.jpg)

## Tire Choices: 

SOFT - Fastest tire compound. However, the tire will wear much quicker. Pirelli (the tire maker) has predicted that tire wear will cause time drop off after 10 laps.

MEDIUM - A harder compound, but will be more durable than the soft compound at the trade off that it’s a little bit slower. Pirelli has predicted that tire wear will cause time drop off after 20 laps.

HARD - The hardest compound. This will be the slowest but MOST DURABLE compound. Pirelli has predicted that drivers will see drop off around 30 laps.

## Constraints:

* During a Formula 1 race, you are allowed to only have 110 kg of fuel with no refueling allowed.
* Tyre failure happens quite often during a race weekend, especially if the driver races on the same compound past their recommended limit. If you instruct Vettel to drive past the compound’s recommended limit, the chance of Vettel suffering a tyre failure and DNF will be ⅓ (33% every 10 laps)
* The starting fuel flow rate is 1.57 kg / per lap. The average fuel consumption per lap when Vettel does a pit stop will also average out to about the same flow per lap.
* Everytime you task Vettel to push, the lap times will increase by 0.3 seconds per lap (according to their tyre compound), but fuel will be consumed at 7% more than normal pace. If you task Vettel to conserve fuel, lap times will decrease by 0.3 seconds per lap (according to their tyre compound), but fuel will be consumed at 13% less than normal pace.
  * (START) 1.57 kg / per lap
  * (PUSH) 1.57 kg / per lap -----> 1.67 kg / per lap
  * (CONSERVE FUEL) 1.57 kg / per lap  -----> 1.37 kg / per lap
  * (PIT)  1.57 kg / per lap
* When you task Vettel to come into the pits for new fresh tyres, about 30 seconds will be added onto your time (1 lap only, not the entire 10 laps check-in). Typically, racers will do about 2-3 pit stops per race. 


## Instructions:

After the start, you will be checking in with your driver after every 10 laps to provide an update. In each update, you will provide Vettel with what lap he’s on, current tyre compound, fuel, and the sum of his time so far in the race. 

In each update, you will be given the option to task Vettel with push (go faster), conserve fuel (go slower) or pit stop (change tyres).

# Make sure you watch the fuel flow and manage the tyres accordingly. Goodluck!