﻿#pragma once
#include "../../Hooks.hpp"
#include "../../Interfaces.hpp"
#include "../../valve_sdk/Interfaces/IGameEvent.hpp"
#include <string>
#include <vector>

static std::vector<std::string> funnyTrashTalk = {
	"Rest in spaghetti never forgetti",
	"Don't be upsetti, have some spaghetti",
	"Was that your spray on the wall or are you just happy to see me?",
	"Shut up, I fucked your dad.",
	"You must be fat because you have a nice voice, and the air needs enough space in your lungs to articulate the sound right.",
	"Guys, if we want to win this, stop writing fucking Klingon, can't understand shit.",
	"LISTEN HERE YOU LITTLE FUCKER, WHEN I WAS YOUR AGE, PLUTO WAS A PLANET!",
	"If I wanted to listen to an asshole I would fart.",
	"Id rather rub my dick with sandpaper than play with you guys.",
	"At least my country has indoor plumbing.",
	"We may have lost the game, but at the end of the day we, unlike you, are not Russians",
	"Bhopped to your mom's house last Sunday, top kek.",
	"Yo momma so fat, she gets stuck at long doors.",
	"Your mom is so fat when she boosts she teamkills",
	"ez katka 8)",
	"Yo mama so fat when she plays Overpass, you can shoot her on Mirage.",
	"I PLAY WITH A RACING WHEEL...",
	"bvfndsubmdsj vudsa,vsjnfn ., .,.,\nSORRY JUST CLEANING THE JIZZ OF MY KEYBOARD!!",
	"How did i get here from watching dog porn? o_O",
	"Cheer up, your small dick isnt noticealbe under ur badness.",
	"So next time I scratch my ass I will think of you, now do everyone a favor and FUCK OFF.",
	"Go climb a wall of dicks.",
	"It's time for a mapchange, isn't it ?",
	"You only killed me because I ran out of health..."
};
static std::vector<std::string> negativeTrashTalk = {
	"Stop playing like KQLY why cant you play more like Tarik?",
	"If CS:GO is too hard for you maybe consider a game that requires less skill, like idk.... solitaire?",
	"Bro you couldn't hit an elephant in the ass with a shotgun with aim like that.",
	"You're the human equivalent of a participation award.",
	"Server cvar 'sv_rekt' changed to 1",
	"Oops, I must have chosen easy bots by accident...",
	"Is this casual? I have 16k...",
	"I thought I already finished chemistry.. So much NaCl around here...",
	"Did you know that csgo is free to uninstall?",
	"Even Noah can't carry these animals...",
	"Options -> How To Play",
	"How much did you tag that wall for??",
	"I thought I put bots on hard, why are they on easy?",
	"Is your monitor on?",
	"You have the reaction time of a dead puppy.",
	"The only thing you carry is an extra chromosome.",
	"Safest place for us to stand is in front of your gun...",
	"Is that a decoy, or are you trying to shoot somebody?",
	"Deranking?",
	"Buy sound next time...",
	"Mad cuz bad",
	"You can't even carry groceries in from the car",
	"I kissed your mom last night. Her breath was globally offensive",
	"Stop buying an awp you $4750 decoy...",
	"You're the reason the gene pool should have a life guard.",
	"Kick your teammate, he's flooring.",
	"Sell your computer and buy a Wii.",
	"You have a reaction time slower than coastal erosion.",
	"They do not deserve like this, they do not deserve for rekt...",
	"Did you grow up near by Tschernobyl or why are you so toxic?",
	"I'm surprised you've got the brain power to keep your heart beating",
	"Even if you would play tetris you would tie up",
	"You don't deserve to play this game. Go back to playing with crayons and shitting yourself",
	"Like what your mother did to you, can I get a drop?",
	"You shoot like an AI designed by a 10 year old",
	"Sorry, I don't speak star wars.",
	"You could not pre-fire a marching band full of elephants.",
	"Internet Explorer is faster than your reactions.",
	"If this guy was the shooter harambe would still be alive.",
	"Theres more silver here than in the cutlery drawer...",
	"Hey mate, what controller are you using?",
	"I bet you're the type of dude that likes it when your toilet paper breaks and your finger slides up your asshole.",
	"FYI: Warmup is over already.",
	"Shut up kid and talk to me when your balls have reached the bottom of your spiderman underwear...",
	"I'm not trash talking, I'm talking to trash.",
	"With aim like that, I pity whoever has to clean the floor around your toilet.",
	"If you want to play against enemies of your skill level just go to the main menu and click 'Offline with Bots'.",
	"Hey man, dont worry about being bad. It's called a trashCAN not a trashCAN'T.",
	"How'd you hit the ACCEPT button with that aim?",
	"You guys were ecoing as well?",
	"Nice $4750 decoy.",
	"If you would chew your food you wouldn't be choking so hard.",
	"At least you did 100 damage to the wall behind me.",
	"You're about as useful as pedals on a wheelchair.",
	"Protip: Using a mouse is recommended.",
	"LOL watchin u play this game is like watching helen keller play tennis.",
	"Everyone who loves you is wrong.",
	"I have not met with anything in natural history more amusing and entertaining than your personal appearance.",
	"Can't hear you from the bottom of the scoreboard.",
	"On a scale from 1 to 10, how old are you?",
	"Why can't I take control of this bot?",
	"You make NiP look good.",
	"I'd say uninstall but you'd probably miss that too",
	"Get the bomb, at least you will carry something this game.",
	"You're going to give me an aneurysm.",
	"The only thing you can throw are rounds.",
	"I am sorry to inform you that your lack of practice, has lead to a underwhelming display of skill aim wise.",
	"You know all those times your parents said video games would get you nowhere? They were right.",
	"This isn't a turn-based game, it's okay to shoot back at the same time.",
	"Choose your excuse: 1.Lags | 2.New mouse | 3.Low FPS | 4.Low team | 5.Hacker | 6.Lucker | 7.Smurf | 8.Hitbox | 9.Tickrate",
	"When I wake up in the morning I have better spray control than your garbage AK47 spray, delete CS kid...",
	"You're as useless as the 'ueue' in 'queue'",
	"Mirros can't talk. Lucky for you, they can't laugh either.",
	"Hey, you have something on your chin... No, the 3rd one down.",
	"If I had a face like yours, I'd sue my parents.",
	"Your only chance of getting laid is to crawl up a chicken's ass and wait.",
	"Some day you'll go far.. and I hope you stay there.",
	"Aha! I see the fuck-up fairy has visited us again.",
	"You must have been born on a highway cos' that's where most accidents happen.",
	"If laughter is the best medicine, your face must be curing the world.",
	"I'm glad to see you're not letting your education get in the way of your ignorance.",
	"Is your ass jealous of the amount of shit that just came out of your mouth?",
	"So, a thought crossed your mind? Must have been a long and lonely journey.",
	"When I see your face there's not a thing I would change... Except the direction I was walking in.",
	"When you were born the doctor threw you out the window, and the window threw you back.",
	"You’re the reason God created the middle finger.",
	"Light travels faster than sound which is why you seemed bright until you spoke.",
	"Did your parents meet at a family reunion by any chance?",
	"I thought I was ugly but evolution really took a step back with you.",
	"Atleast hitler knew when to kill himself.",
	"I need an apology letter, can I borrow your birth certificate?",
	"It was a sad day at the hospital when you crawled out of the abortion bucket.",
	"Your family tree must be a circle.",
	"Your idea of a comeback is jerking off into a fan.",
	"It's impossible to underestimate you.",
	"It's not that you're intimidating, youre face is just difficult to look at.",
	"I'd love to see things from your perspective, but I don't think I could shove my head that far up my ass.",
	"If we learn from our mistakes, your parents must be geniuses now.",
	"Your family must have a motto of Incest is Wincest for you to be that retarded.",
	"You're the human equivalent to biting into an oatmeal raisin cookie thinking it's chocolate chip.",
	"Yo momma's so damn fat they named her after your throwing skills."
};
static std::vector<std::string> edgyTrashTalk = {
	"You must be russian, I smell your drunk mom.",
	"Maybe if you stopped taking loads in the mouth you wouldn't be so salty.",
	"Who are you sponsored by? Parkinson's?",
	"You're almost as salty as the semen dripping from your mum's mouth.",
	"If you were a CSGO match, your mother would have a 7day cooldown all the time, because she kept abandoning you.",
	"I could swallow bullets and shit out a better spray than that...",
	"Dude you're so fat you run out of breath rushing B",
	"Did you learn your spray downs in a bukkake video?",
	"Your nans like my ak vulcan, battle-scarred.",
	"Watching you play is making my brain cells want commit suicide.",
	"At least I don't live in the world's most corrupt country.",
	"Isn't it uncomfortable playing Counterstrike in the kitchen?",
	"My knife is well-worn, just like your mother.",
	"Are you one of those special kids?",
	"If I wanted a comeback, I'd get it off your moms face.",
	"Go have a 3 sum with your sister and your cousin you fucking hill billy redneck.",
	"Do you make eye-contact when you're fucking your dad in the ass?",
	"You dropped that bomb just like your mom dropped you on your head as a kid.",
	"You define autism",
	"Your shots are like a bad girlfriend: No Head",
	"You can feel the autism",
	"Which one of your 2 dads taught you how to play CS?",
	"I'm the reason your dad's gay.",
	"I support abortion up to whatever age you are.",
	"Shut up, you have two dads.",
	"I PRAY TO GOD A PACK OF WOLVES RAPES YOU IN THE DEAD OF WINTER AND FORCES YOU TO WALK HOME BAREFOOT!",
	"Go rub your cock against a cheese grater you titcrapping twigfucker.",
	"Some babies were dropped on their heads but you were clearly thrown at a wall.",
	"You suck so much dick, that you turn your entire team gay."
};
static std::vector<std::string> darkTrashTalk = {
	"CRY HERE ---> \\__/ <--- Africans need water.",
	"You look like you have parkinsons you shake and bake fuck-knuckle.",
	"You sound like your parents beat each other in front of you.",
	"Don't be a loser, buy a rope and hang yourself.",
	"My dead dad has better aim than you, it only took him one bullet",
	"I'd say your aim is cancer, but cancer kills.",
	"Do you feel special? Please try suicide again... Hopefully you will be successful this time.",
	"If I were to commit suicide, I would jump from your ego to your elo.",
	"Imagine your potential if you didn't have parkinsons."
};

class KillChat : IGameEventListener2
{
public:
	KillChat();
	~KillChat();
	virtual void FireGameEvent(IGameEvent* pEvent);
	int GetEventDebugID() override;
};