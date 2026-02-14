# The Art of the Prompt: Empowering Our Team with AI

**February 14, 2026** **;** **30 min read**
**By: Shubhra Awasthi**

### _A Guide to Prompt Engineering_

---

## 🛠️ What is Prompt Engineering?

Think of this guide as your "translator’s handbook."

Despite the technical name, **Prompt Engineering is not about coding, math, or complex computer science.** It is simply the art of giving clear, strategic instructions to an AI to ensure it delivers high-quality, actionable results on the first try.

If you have ever had to:

- Leave detailed instructions for a new intern.
- Order a highly specific coffee (Large, oat milk, extra hot, no foam!).
- Explain a complex mortgage product to a first-time homebuyer.

...then you already have the foundational skills to be an AI wizard.

---

## 💡 Why This Matters to You

This documentation is designed to be a simple, easy-to-digest manual for everyone in the company. We have stripped away the technical jargon and replaced it with:

- **Simple Definitions:** Understanding the "why" without the headache.
- **Banking-Related Examples:** See how these tools apply to your actual desk.
- **Plug-and-Play Templates:** Ready-to-use formulas for your daily tasks.

Whether you are summarizing a 100-page compliance report, drafting sensitive client emails, or analyzing branch data, these techniques will help you **work faster, smarter, and with greater precision.**

---

_Ready to start? Let’s dive into the core settings and techniques that will turn the AI into your most reliable digital teammate._

---

## 4. The Recipe for a Perfect Prompt (Prompt Elements)

A perfect prompt is like a beautifully structured club sandwich. If you just throw a piece of ham at someone, it's not a sandwich. You need all the layers to make it good:

1.  **Instruction (The Bread):** What exactly do you want the AI to do? _(e.g., "Summarize this email.")_
2.  **Context (The Meat):** What is the background story? _(e.g., "I am a branch manager and this email is from a very upset VIP client.")_
3.  **Input Data (The Veggies):** The actual information the AI needs to process. _(e.g., Copying and pasting the actual angry email.)_
4.  **Output Indicator (The Sauce):** How do you want it served to you? _(e.g., "Give me the summary as a 3-point bulleted list.")_

---

## 5. Golden Rules for Chatting with AI (General Tips)

Print these out and stick them on your monitor!

- **Start Simple:** Don't write a giant paragraph if a sentence will do. Start basic, see what the AI gives you, and add more details if needed.
- **Be Specific:** "Write an email about loans" is a bad prompt. "Write a 3-paragraph email to a first-time homebuyer explaining our new mortgage rates in a friendly, welcoming tone" is a _perfect_ prompt.
- **Avoid "Fluff" (Impreciseness):** Don't tell the AI to "make it sound smart." Instead, say "use professional banking terminology."
- **Say What TO Do, Not What NOT To Do:** AI gets easily confused by negative instructions. Instead of saying, "Don't be overly casual," tell it to, "Maintain a strictly professional tone."

---

_Ready for the magic? In the next section, we’ll dive into the actual **Prompting Techniques**—the secret spells that make the AI do your hardest tasks for you!_

---

# Prompting Techniques: The Secret Spells

Now that we know how to talk to the AI, let's learn some specific techniques to get the absolute best results. We will start with the easiest one!

---

## 1. Zero-Shot Prompting

"Zero-Shot" is a fancy way of saying "Zero Examples Given." It means you are asking the AI to do a task cold, without providing any cheat sheets, templates, or prior examples of what you want. You are relying on the fact that the AI has already read the entire internet and naturally understands what you're asking for.

Think of it like asking an experienced bank teller to process a standard deposit. You don't need to show them a manual on how to do it first; you just hand them the check and they know what to do!

**Example Showcase:**
Let's say we want the AI to read an incoming customer email and tell us if the customer is happy, neutral, or angry (also known as "sentiment analysis").

> **You (The Prompt):** > Classify the mood of the following customer email into Positive, Neutral, or Negative.
> _Email:_ "I have been on hold for 45 minutes to dispute a \$2 fee, my coffee is now freezing cold, and if I have to hear your jazz hold music one more time, I am going to move my mortgage to a different bank."
> _Mood:_
>
> **The AI (The Output):** > Negative.

_See? We didn't have to show the AI an example of an angry email first. It just inherently knew that cold coffee and jazz hold music equaled a bad time._

**Usecase (Template):**
Use this for simple, straightforward tasks where the AI doesn't need a specific formatting template to get the job done (like basic translations, summarizing short texts, or simple categorization).

> **Template to copy/paste:**
> [Action word: e.g., Classify / Translate / Summarize] the following text.
>
> Text: [Insert your text or data here]
>
> Result:

## 2. Few-Shot Prompting

Remember the "Zero-Shot" technique where we just threw a task at the AI and hoped for the best? **Few-Shot Prompting** is the slightly more patient approach. It means giving the AI a few quick examples of exactly what you want before asking it to do the real thing.

Imagine hiring a brand new teller. Instead of just pointing at a pile of messy paperwork and saying "Sort these," you say, "Here is how we sort them. Lunch receipts go in the 'Meals' pile. Printer ink goes in the 'Office' pile. Now, you try." You are showing, not just telling!

**Example Showcase:**
Let's say we want the AI to automatically categorize our branch's expense reports based on short descriptions, but it keeps getting confused. We just give it a few "shots" (examples) first:

> **You (The Prompt):**
> _Example 1:_ Client dinner at a steakhouse -> Category: Entertainment
> _Example 2:_ Buying 500 branded bank pens -> Category: Marketing
> _Example 3:_ Fixing the branch's broken ATM -> Category: Maintenance
>
> _Now do this one:_ Buying an emergency dozen donuts for the Monday morning team meeting -> Category:
>
> **The AI (The Output):** > Category: Office Supplies (or maybe Morale!)

_Because we showed it the exact pattern we wanted, the AI knew exactly how to format its answer without any extra babbling._

**Usecase (Template):**
Use this when you want the AI to output something in a very specific format or category that it might not guess correctly on its own.

> **Template to copy/paste:**
> Here are some examples of what I want:
> [Example Input 1] -> [Example Output 1]
> [Example Input 2] -> [Example Output 2]
>
> Now, do the same for this:
> [Your actual input] ->

---

## 3. Chain-of-Thought Prompting

**Chain-of-Thought (CoT)** is a fancy way of telling the AI: _"Show your math!"_ Sometimes, if you give the AI a complicated problem, it panics, rushes, and guesses the wrong answer. But if you force it to break the problem down and think through it **step by step**, it suddenly becomes a genius. It’s exactly like when a customer asks a really convoluted question about their mortgage rate—you have to write out the steps on a notepad so you don't confuse yourself.

**Example Showcase:**
Let's see what happens when a customer has a very confusing transaction history.

> **You (The Prompt):** > A customer had \$500 in their checking account. They deposited a \$1,200 paycheck. Then, three separate auto-pays of \$100 hit their account. Finally, they bought a \$4 coffee. What is their final balance? _Let's think step by step._
>
> **The AI (The Output):** > 1. The customer started with \$500. 2. They deposited \$1,200, making the new balance \$1,700 (\$500 + \$1,200). 3. Three auto-pays of \$100 were deducted, which equals \$300. The new balance is \$1,400 (\$1,700 - \$300). 4. They bought a \$4 coffee, so \$1,400 - \$4 = \$1,396.
>
> The final balance is \$1,396.

_If we hadn't typed the magic words "Let's think step by step," the AI might have accidentally skipped a step or added the coffee instead of subtracting it!_

**Usecase (Template):**
Use this for any task that involves math, logic, or making a decision based on multiple rules (like checking if someone qualifies for a loan based on three different credit criteria).

> **Template to copy/paste:**
> [Insert your complex question, logic puzzle, or math problem here]
>
> Let's think step by step to find the answer.

## 4. Meta Prompting

**Meta Prompting** is basically AI Inception. It’s when you use the AI to write a prompt _for_ the AI. If you don't know the best way to ask the AI to do something, you just ask it: _"Hey, what's the best way to ask you to do this?"_ It’s like asking your manager for advice on how to ask them for a day off. You're using the system to beat the system!

**Example Showcase:**
Let's say you need to write a highly delicate email to a client who keeps forgetting to sign their loan documents, but you have no idea how to phrase your prompt to get the right tone.

> **You (The Prompt):** > I need to write an email to a client named Bob who keeps forgetting to sign his mortgage papers. I want you to write the absolute best prompt I can use to make you write this email perfectly.
>
> **The AI (The Output):** > Here is the best prompt you can use: _"Act as a friendly but firm senior loan officer. Write a 3-paragraph email to a client named Bob. Remind him that his mortgage rate lock expires in 48 hours, and we urgently need his signature on the attached documents to secure his home loan. Keep the tone professional, helpful, and slightly urgent, but not aggressive."_

_Boom! Now you just copy and paste the AI's own prompt right back to it, and you get a masterpiece._

**Usecase (Template):**
Use this when you have a big task but you are staring at a blank screen and don't know how to start formatting your request.

> **Template to copy/paste:**
> I want to achieve [Describe your goal, e.g., summarize a 50-page financial report].
> Write the best, most detailed prompt I can give you so that you produce the perfect result for me.

---

## 5. Self-Consistency

**Self-Consistency** is the "Ask Three Tellers" rule. If you ask one teller to count a massive bag of mixed coins, they might make a mistake. But if you ask _five_ different tellers to count that same bag, and four of them tell you the total is \$452.50, you can be pretty confident the answer is \$452.50.

With AI, you just ask it to solve a complex logic or math problem multiple times, and then you tell it to pick the most common answer. Majority rules!

**Example Showcase:**
We need to figure out a tricky scheduling conflict for the branch staff.

> **You (The Prompt):** > We need 3 people to work the vault on Saturday. Sarah can only work if John works. John cannot work if Mike works. Mike is already scheduled. Who can work the vault?
> _Think through this step-by-step, generate 3 different independent ways to solve this, and give me the final answer that appears most often._
>
> **The AI (The Output):** > _Solution 1:_ Since Mike is working, John cannot work. Since John cannot work, Sarah cannot work. Answer: None of these three can work the vault together.
> _Solution 2:_ Mike is scheduled. Rule says John can't work with Mike. So John is out. Sarah needs John, so Sarah is out. Answer: None.
> _Solution 3:_ Mike is working. John is blocked by Mike. Sarah is blocked by John. Answer: None.
>
> _Most consistent final answer:_ None of them can work the vault!

_By forcing it to double and triple-check its own logic, we avoid silly AI math errors!_

**Usecase (Template):**
Use this for puzzles, complex schedules, or tricky financial logic where you absolutely cannot afford a careless hallucination.

> **Template to copy/paste:**
> [Insert your complex logic or math problem]
>
> Please think through this step-by-step. Generate 3 different, independent thought processes to solve this problem. Then, compare your results and give me the final answer that is the most consistent among all your attempts.

---

## 6. Generate Knowledge Prompting

**Generate Knowledge Prompting** is making the AI do its homework before it takes the test.

Sometimes, if you ask the AI a highly specific question, it panics and guesses. But if you first tell the AI, _"Write down everything you know about this topic on a piece of scratch paper,"_ and _then_ ask the question, it suddenly gives a brilliant answer because it just refreshed its own memory!

**Example Showcase:**
Let's say a customer asks if they can use their new corporate credit card to buy cryptocurrency.

> **You (The Prompt):** > _Step 1:_ Generate 4 key facts about standard banking regulations regarding corporate credit cards and cryptocurrency purchases.
> _Step 2:_ Based on those facts, answer this customer's question: "Can I use my corporate card to buy Bitcoin?"
>
> **The AI (The Output):** > _Generated Facts:_ > 1. Corporate cards are strictly for business expenses. 2. Cryptocurrencies are highly volatile assets. 3. Most major banks block crypto purchases on credit cards due to fraud and anti-money laundering (AML) risks. 4. Crypto purchases are often treated as cash advances, which have strict limits.
>
> _Answer to Customer:_ Based on standard banking policies, no, you generally cannot use a corporate credit card to buy Bitcoin. It violates business expense policies and is usually blocked by the bank's fraud prevention systems.

_By making it list the facts first, the AI gives a rock-solid, policy-based answer instead of a vague guess._

**Usecase (Template):**
Use this when you are asking the AI to make a judgment call or answer a question about a niche topic.

> **Template to copy/paste:**
> Generate 5 factual bullet points about [Topic/Policy].
> Then, using ONLY those facts, answer the following question: [Insert Question].

---

## 7. Retrieval Augmented Generation (RAG)

**RAG** (Retrieval Augmented Generation) is giving the AI an Open-Book Test!

Normally, an AI relies entirely on its memory—and sometimes, its memory is outdated (like thinking the 2021 interest rates are still active). RAG fixes this. It acts like a librarian. When you ask a question, RAG first runs to the bank's secure digital filing cabinet, grabs the exact, up-to-date PDF manual, hands it to the AI, and says: _"Read this specific page first, THEN answer the human."_

**Example Showcase:**
A customer wants to know the exact penalty fee for an overdraft on our new "Platinum Plus" account, which launched yesterday. The AI's standard memory has no idea what that is.

> **You (The Prompt via a RAG system):** > _[Behind the scenes, the system automatically searches the bank's intranet for "Platinum Plus Overdraft Fee" and pastes the text into the prompt]_
>
> Based on this official bank document: _"The Platinum Plus account features a grace period of 24 hours for overdrafts. After 24 hours, a flat fee of \$15 is applied."_
>
> Answer the customer's question: "What is the overdraft penalty for my Platinum Plus account?"
>
> **The AI (The Output):** > If you overdraft your Platinum Plus account, you have a 24-hour grace period to bring the balance positive. If it remains overdrawn after 24 hours, you will be charged a \$15 flat fee.

_No hallucinations, no guessing. Just pure, accurate bank policy!_

**Usecase (Template):**
_(Note: True RAG usually requires your IT department to hook the AI up to your internal databases. But you can do "Manual RAG" yourself!)_

> **Template to copy/paste:**
> Act as a knowledgeable bank representative. Use ONLY the information provided in the text below to answer the question. If the answer is not in the text, say "I do not have that information."
>
> [Paste the text of the policy/email/document here]
>
> Question: [Insert Question]

## 8. Prompt Chaining

**Prompt Chaining** is the "Assembly Line" technique. Instead of asking the AI to build a whole car in one go (which usually results in the steering wheel being attached to the roof), you ask it to build the engine, then pass that engine to the next station, then add the doors, and so on.

You break a massive, complicated task into a series of smaller prompts. The output of the _first_ prompt becomes the input for the _second_ prompt.

**Example Showcase:**
Let's say a customer sends in a rambling, angry email, and we need to log the issue and reply to them. Doing this in one prompt might cause the AI to miss details. Let's chain it!

> **You (Prompt 1 - The Extraction):** Read this email and extract only the core problem in one sentence.
> _Email:_ "I tried to pay for my family's dinner at Paradise Biryani in Hyderabad using your banking app, and the UPI payment failed twice! It was incredibly embarrassing! Fix your servers!"
>
> **AI (Output 1):** The core problem is a UPI payment failure at a restaurant.
>
> **You (Prompt 2 - The Drafting):** Take this core problem: _"UPI payment failure at a restaurant"_ and write a 2-sentence, empathetic apology SMS from the bank's customer support.
>
> **AI (Output 2):** "We are so sorry you experienced a UPI payment failure during your meal; we understand how frustrating that is. Our technical team is currently investigating the server issue to ensure this doesn't happen again."

_By breaking it down, the AI didn't get distracted by the biryani—it perfectly extracted the issue and wrote a flawless text!_

**Usecase (Template):**
Use this for multi-step office workflows, like reviewing a loan application, extracting the missing documents, and then drafting an email requesting those specific documents.

> **Template to copy/paste:**
> _(Step 1)_ Read this [Text] and extract [Specific Information].
> _(Step 2)_ Using the information you just extracted, please [Perform Next Task, e.g., write an email, categorize it, etc.].

---

## 9. Tree of Thoughts (ToT)

**Tree of Thoughts** is the "Chess Grandmaster" or "Brainstorming Session" technique.

Normally, an AI just picks the first idea that pops into its head and runs with it. With Tree of Thoughts, you force the AI to act like a room full of strategists. It maps out three different possible solutions, evaluates the pros and cons of each one, abandons the bad ideas, and only gives you the winning strategy.

**Example Showcase:**
We need to figure out the best way to handle a branch that has too many customers waiting in line during lunch hour.

> **You (The Prompt):** > We have a problem: Wait times at our main branch during the 12 PM - 2 PM lunch rush are exceeding 30 minutes.
> Brainstorm 3 completely different strategies to solve this. For each strategy, evaluate the potential cost, the impact on staff, and the customer reaction. Finally, pick the best strategy and explain why it wins.
>
> **The AI (The Output):** > _Strategy A (Hire more staff):_ Cost is high. Staff impact is positive. Customers are happy.
> _Strategy B (Push mobile app usage):_ Cost is low. Staff impact is neutral. Older customers might be frustrated.
> _Strategy C (Staggered employee lunches):_ Cost is zero. Staff might be slightly annoyed at changing schedules. Customers get faster service.
>
> _Evaluation:_ Strategy A is too expensive. Strategy B takes months to adopt. Strategy C is an immediate fix.
> _Final Recommendation:_ Go with Strategy C (Staggered Lunches) as it requires no budget approval and immediately puts more tellers at the desk during peak hours.

_Instead of just blurting out "Hire more people!", it actually thought through the budget and logistics like a real manager!_

**Usecase (Template):**
Use this when you need help making strategic decisions, solving complex operational problems, or evaluating different business plans.

> **Template to copy/paste:**
> I need to solve this problem: [Describe problem].
> Please generate 3 distinct possible solutions. Walk through the pros and cons of each solution step-by-step, evaluating [Factor 1, e.g., cost] and [Factor 2, e.g., time]. Conclude by selecting the most optimal path.

---

## 10. Automatic Reasoning and Tool-use (ART)

**ART** is giving the AI an "Open Book Test with a Calculator."

A dirty little secret about AI is that it is surprisingly bad at math. It doesn't actually "calculate" numbers; it just predicts what number usually comes next in a sentence. ART fixes this by allowing the AI to pause its typing, reach out and use an actual tool (like a Python calculator or a web search), grab the exact right answer, and then finish its sentence.

**Example Showcase:**
A customer wants to know exactly how much interest they will owe on a highly specific loan over 7 years.

> **You (The Prompt):** > A customer is taking out a \$14,567 personal loan at a 6.4% annual interest rate. How much total interest will they pay after exactly 7 years? Use the calculator tool before answering.
>
> **The AI (Behind the Scenes):** > _Wait, I am bad at math. Let me use the calculator tool._
> _[Tool execution: 14567 _ ((1 + 0.064)^7 - 1)] -> Result: \$7,922.45\*
>
> **The AI (The Output):** > Based on a \$14,567 loan at a 6.4% rate over 7 years, the customer will pay exactly \$7,922.45 in total interest.

_Because it used a tool, you don't have to worry about the AI accidentally costing the bank thousands of dollars due to a hallucinated math error!_

**Usecase (Template):**
_(Note: Using external tools usually requires using a specific AI platform that has plugins enabled, like ChatGPT Plus or specific internal banking AI agents.)_

> **Template to copy/paste:**
> Calculate the following: [Insert complex math or data query].
> Please use your [Search / Calculator / Code] tool to verify the exact numbers before providing the final answer.

## 11. Automatic Prompt Engineer (APE)

**APE** is basically the AI acting as its own manager.

Imagine you are trying to write the perfect email to get a new project approved by the branch manager. You might write five different drafts, show them to your coworkers, and ask, _"Which one sounds best?"_ APE does exactly this. Instead of you guessing the magic words, you ask the AI to generate a bunch of different prompts for a task, test them all behind the scenes, and automatically use the one that scores the best! It is the AI optimizing itself so you don't have to.

**Example Showcase:**
We need to pull specific tax ID numbers out of a mountain of messy, handwritten-then-scanned loan applications, but our simple prompts keep failing.

> **You (The Prompt):** I need to extract 9-digit tax ID numbers from messy customer files. Generate 5 different, highly effective instructions to do this. Then, test which instruction works best and give me the winning prompt!
>
> **The AI (The Output):** > _Testing Prompt 1..._ ❌ Missed numbers with dashes.
> _Testing Prompt 2..._ ❌ Confused dates with tax IDs.
> _Testing Prompt 5..._ ✅ Flawless extraction.
>
> _Winning Prompt to use:_ "Scan the following document for any sequence of 9 digits, ignoring hyphens and spaces. Do not include dates. Return only the 9-digit sequences."

_You just made the AI do the heavy lifting of figuring out how it wants to be talked to!_

**Usecase (Template):**
Use this when you have a repetitive, high-stakes task (like data entry) and your current prompts are giving you sloppy results.

> **Template to copy/paste:**
> I want to achieve the following goal: [Insert Goal].
> Please generate 3 different, highly detailed prompts that would instruct an AI to complete this goal perfectly. Tell me which one you think is the best and why.

---

## 12. Active-Prompt

**Active-Prompt** is the "Focused Tutoring Session."

When you train a new credit analyst, you don't waste time teaching them how to approve a flawless, zero-risk application—they already get that. Instead, you figure out which weird applications confuse them the most, and you specifically sit down to train them on _those_ edge cases. Active-Prompt is doing exactly that. You find the questions the AI is most uncertain about, and you step in to give it specific examples to clear up its confusion.

**Example Showcase:**
The AI is automatically categorizing our branch's customer support tickets perfectly 90% of the time. But it's totally confused by tickets regarding the new mobile app update.

> **You (The Workflow):** > _Step 1:_ You notice the AI keeps guessing wrong on app-related tickets. It's uncertain.
> _Step 2 (The Prompt):_ Here are three examples of how to handle the confusing mobile app tickets you keep messing up:
>
> - "App crashes on login" -> Category: Tech Support (Urgent)
> - "Can't find the transfer button" -> Category: User Guidance
> - "Screen is frozen on my profile" -> Category: Tech Support (Standard)
>
> Now, categorize this new ticket: "The app just closed when I tried to send money via UPI."
>
> **The AI (The Output):** Category: Tech Support (Urgent)

_By focusing only on what the AI didn't know, we patched its blind spot without having to re-teach it everything else!_

**Usecase (Template):**
Use this when you are doing Few-Shot prompting (giving examples), but you want to be strategic about _which_ examples you provide. Always provide examples of the hard stuff!

> **Template to copy/paste:**
> You seem to struggle with [Insert confusing topic]. Here are 3 exact examples of how I want you to handle this specific scenario:
>
> 1. [Confusing Input A] -> [Correct Output A]
> 2. [Confusing Input B] -> [Correct Output B]
>
> Now, please process: [Your actual input]

---

## 13. Directional Stimulus Prompting (DSP)

**Directional Stimulus Prompting** is the "Sticky Note Cheat Sheet."

Imagine you hand a massive, 100-page regulatory update to an intern and say, _"Summarize this."_ They might give you a summary of the boring legal preamble. But if you stick a Post-it note on the front that says, _"Summarize this, but MAKE SURE you mention 'interest rates,' 'penalty fees,' and 'the December deadline',"_ they will give you exactly what you need. DSP is just giving the AI a list of mandatory keywords to guide its focus.

**Example Showcase:**
We just had a grueling 2-hour strategic meeting about opening a new branch, and the AI transcribed the whole thing. We need a summary for the regional director.

> **You (The Prompt):** Please summarize the transcript of our strategy meeting.
> _Directional Stimulus (Keywords to include):_ Make absolutely sure your summary includes the decisions regarding "ATM installation," "security vendor," and "grand opening budget."
>
> **The AI (The Output):** The team agreed to move forward with the new branch. The **grand opening budget** was finalized at \$15,000. It was decided that **ATM installation** will happen in phase two, and we will renew the contract with our current **security vendor** rather than looking for a new one.

_No fluff, no missing details. The AI followed the breadcrumbs you left for it!_

**Usecase (Template):**
Use this anytime you need a summary of a long document, email thread, or meeting, and you want to ensure the AI doesn't accidentally leave out the most important topics.

> **Template to copy/paste:**
> Please summarize the following text.
> Crucial Instruction: Your summary MUST include and focus on the following keywords/topics: [Keyword 1], [Keyword 2], [Keyword 3].
>
> Text: [Insert long text here]

## 14. Program-Aided Language Models (PAL)

**PAL** is the "English Major, Not a Math Major" rule.

Here is a secret: AI models are incredible at reading, writing, and talking, but they are surprisingly terrible at math. If you ask an AI to do complex arithmetic in its head, it often just confidently guesses the wrong number.

PAL fixes this by telling the AI, _"Please do not try to do the math yourself. Instead, just write the formula, hand it to a real calculator (a computer program), and let the computer do the math."_ It’s exactly like when a customer asks you for their compound interest breakdown—you don't do long division on a napkin, you type the formula into the banking software and read them the result!

**Example Showcase:**
Let's say we need to calculate a highly specific and slightly messy expense report for the Hyderabad branch's end-of-month party.

> **You (The Prompt):** > We bought 45 plates of biryani at ₹250 each, and 45 extra gulab jamuns at ₹40 each. We had a branch discount of 15% on the total food bill. Then, we added a flat ₹500 delivery tip. How much is the final bill?
> _Write a Python code script to calculate this exactly, rather than answering directly._
>
> **The AI (Behind the scenes, it writes the code instead of guessing):** >
> plates_of_biryani = 45
> cost_per_biryani = 250
> gulab_jamuns = 45
> cost_per_jamun = 40
>
> total*food_cost = (plates_of_biryani * cost*per_biryani) + (gulab_jamuns * cost_per_jamun)
> discount = total_food_cost \* 0.15
> discounted_food_cost = total_food_cost - discount
> final_bill = discounted_food_cost + 500
>
> print(final_bill)
>
> _(The computer runs the code and gets ₹11,592.50)_
>
> **The AI (The Output):** > The final bill for the branch party, after the 15% discount and the ₹500 tip, is exactly ₹11,592.50.
>
> ```
>
> ```

_Because the AI wrote the formula and let the computer run it, there is a 0% chance of a hallucinated math error!_

**Usecase (Template):**
Use this for any prompt involving heavy financial calculations, prorated loan interest, complex dates, or branch budgets where a single wrong digit could cause a massive headache.

_(Note: To use PAL fully, you usually need an AI environment that can run code, like Gemini's Advanced data analysis or ChatGPT's Code Interpreter)._

> **Template to copy/paste:**
> I need to solve the following mathematical/logic problem:
> [Insert messy numbers, loan details, or dates here]
>
> Please do not calculate the answer directly. Instead, write a short Python script to solve this step-by-step, run the code, and give me the final calculated result.

## 15. ReAct (Reasoning and Acting)

**ReAct** is the "Talk to Yourself While You Work" technique.

Have you ever watched a really good bank teller handle a confusing customer problem? They usually narrate what they are doing out loud. _"Okay, I need to find why your card was declined (Thought). Let me look up your account history (Action). Ah, I see a block placed yesterday (Observation). Now, let me check who placed the block (Thought). Let me call the fraud department (Action)..."_

ReAct forces the AI to do exactly this: **Re**ason, then **Act**, then Observe, and repeat. Instead of just guessing an answer in one shot, the AI writes down its thought process, takes an action (like searching a database or using a calculator), looks at the result, and _then_ decides what to do next. It prevents the AI from rushing and making silly mistakes.

**Example Showcase:**
Let's say a VIP client calls the Hyderabad branch and asks a tricky question that requires checking multiple systems.

> **You (The Prompt):** > A client wants to know if they have enough IDFC FIRST Bank reward points to buy the latest Apple AirPods Pro, and if not, how much cash they need to add. _Use the ReAct format to solve this._
>
> **The AI (The Output):** > **Thought 1:** I need to find out the current price of Apple AirPods Pro and how many reward points the client has. First, let me check the client's point balance.
> **Action 1:** [Search Internal Database: "Client VIP-8492 Reward Points"]
> **Observation 1:** The client has 15,000 reward points (Value: ₹3,750).
>
> **Thought 2:** Now I need to find the current market price of the AirPods Pro.
> **Action 2:** [Web Search: "Apple AirPods Pro price India"]
> **Observation 2:** The current price is ₹24,900.
>
> **Thought 3:** I have both numbers. I need to subtract the value of the points from the total price to find the cash difference. ₹24,900 - ₹3,750 = ₹21,150. I can now answer the customer.
>
> **Final Answer:** You currently have 15,000 reward points (worth ₹3,750). The AirPods Pro cost ₹24,900. You will need to use your points plus an additional ₹21,150 in cash to complete the purchase!

_By forcing it to Think -> Act -> Observe, the AI acts like a seasoned detective rather than a panicked intern blurting out a guess!_

**Usecase (Template):**
Use this when building advanced chatbots or AI agents for the bank that actually need to look up information in real-time before answering a customer.

> **Template to copy/paste:**
> Solve the following customer request by alternating between Thought, Action, and Observation.
> Request: [Insert complex customer question here]
>
> Use this format:
> Thought: [What you need to do next]
> Action: [The tool or search you are using]
> Observation: [The result of your action]
> ...(Repeat as many times as needed)...
> Final Answer: [Your response to the customer]

## 16. Multimodal Chain-of-Thought (Multimodal CoT)

**Multimodal CoT** is the "Show and Tell with a Magnifying Glass" technique.

Let's break down that scary word: "Multimodal" just means using _more than one mode_ of communication—specifically, text **plus** images.

We already know that "Chain-of-Thought" (CoT) means forcing the AI to think step-by-step so it doesn't make silly mistakes. Well, Multimodal CoT is doing that exact same step-by-step reasoning, but while looking at a picture! It's like handing a teller a blurry, coffee-stained physical check and saying, _"Look at this, read it out loud, point to the numbers, and tell me exactly what you see before you deposit it."_

**Example Showcase:**
Let's say a customer uploads a photo of a messy handwritten check to our banking app, and the automated system is confused. We need the AI to review the image.

> Please look at this check image. Think step-by-step about what is written in the number box versus the text line, and tell me if I should approve a \$1,500 deposit.
>
> **The AI (The Output):** > **Step 1 (Visual Check):** I am looking at the numerical box on the right side of the check. It clearly says "\$1,500.00".
> **Step 2 (Reading Check):** I am now reading the handwritten cursive line in the middle. It says "One hundred and fifty dollars".
> **Step 3 (Logic):** There is a mismatch. Standard banking policy dictates that the written words take legal precedence over the numerical box.
>
> **Final Answer:** Do not approve a \$1,500 deposit. Legally, this check is only valid for \$150. (Also, you might want to call the customer and let them know!)

_By forcing it to explain what it saw step-by-step, the AI caught the discrepancy perfectly instead of just blindly reading the biggest number on the page!_

**Usecase (Template):**
Use this anytime you are uploading a photo to the AI—like a scanned ID card, a confusing pie chart from a quarterly meeting, or a messy receipt—and you need it to analyze the image without jumping to conclusions.

> **Template to copy/paste:**
>
> Based on the attached image and the following question: [Insert your question].
>
> Please look closely at the image and think through your answer step-by-step before giving me the final conclusion.

---

## Final Thoughts: Your AI Journey Starts Here

Congratulations! You’ve just completed your first deep dive into the world of **Prompt Engineering**.

By now, you should feel confident that talking to an AI isn’t a "tech thing"—it’s a **communication thing**. Whether you are using _Chain-of-Thought_ to solve a complex loan calculation or _Directional Stimulus_ to focus a meeting summary, you now have the tools to make AI work for you, rather than the other way around.

### Thank You for Reading!

Thank you for taking the time to explore this guide. As we continue to innovate here at **DBS**, your ability to leverage these tools will be a key driver in making our operations smoother and our service to clients even better.

### 📚 Want to Go Deeper?

While this guide was designed to be a fun and simple introduction for our team, there is a whole world of advanced AI research out there.

All the core concepts and techniques documented in this guide were adapted from the **[Prompt Engineering Guide (promptingguide.ai)](https://www.promptingguide.ai)**.

If you are curious about the technical papers, latest research findings, or more advanced developer-level techniques, we highly recommend visiting their website. It is the gold standard for learning how to master Large Language Models.

---

**Happy Prompting!**
