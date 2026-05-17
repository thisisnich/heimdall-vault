const flashcards = [
    {
        question: "What is a project?",
        answer: "A unique effort with:<ul><li>Defined beginning and end</li><li>Specific deliverables</li><li>Defined resources</li></ul>",
        critical: false
    },
    {
        question: "What are the 3 key differences between a Project and a Business Process?",
        answer: "<table><tr><th>Project</th><th>Business Process</th></tr><tr><td>Has a beginning and an end</td><td>Repeated over and over</td></tr><tr><td>Produces different output/deliverable</td><td>Produces same output each time</td></tr><tr><td>No regular work assignments</td><td>Has regular work assignments</td></tr></table><p><strong>Example:</strong> Custom house (project) vs Standard house (business process)</p>",
        critical: false
    },
    {
        question: "What are the 3 constraints in project management?",
        answer: "<ol><li><strong>Time</strong> (schedule/duration)</li><li><strong>Cost</strong> (budget)</li><li><strong>Scope</strong> (features/deliverables)</li></ol><p>These must be balanced to maintain quality.</p>",
        critical: true
    },
    {
        question: "QUIZ: What happens when the duration of the project is DECREASED?",
        answer: "<ul><li><strong>Increase the cost</strong> (hire more people/resources), AND/OR</li><li><strong>Decrease the scope</strong> (reduce features)</li></ul>",
        critical: true
    },
    {
        question: "QUIZ: What happens if the budget (cost) of the project is DECREASED?",
        answer: "<ul><li><strong>Increase the project duration</strong> (reduce manpower), AND/OR</li><li><strong>Decrease the scope</strong> (reduce features)</li></ul>",
        critical: true
    },
    {
        question: "QUIZ: What happens if project scope is INCREASED?",
        answer: "<ul><li><strong>Increase project cost</strong> (more resources needed), AND/OR</li><li><strong>Increase project duration</strong> (more time needed)</li></ul>",
        critical: true
    },
    {
        question: "What are the 3 main goals of project management?",
        answer: "<ol><li>Complete project <strong>on time</strong></li><li>Finish <strong>within budget</strong></li><li>Achieve <strong>customer satisfaction</strong></li></ol>",
        critical: false
    },
    {
        question: "What are the 5 phases in the full cycle of a project?",
        answer: "<ol><li>Project initiation and organising</li><li>Project planning</li><li>Project execution</li><li>Project control and monitoring</li><li>Project closure</li></ol>",
        critical: false
    },
    {
        question: "What are the 4 main phases of project management (simplified)?",
        answer: "<ol><li><strong>Initiation & Organisation</strong></li><li><strong>Planning</strong></li><li><strong>Execution, Monitoring & Control</strong></li><li><strong>Closure</strong></li></ol>",
        critical: false
    },
    {
        question: "What are the key activities in Project Initiation & Organisation?",
        answer: "<ul><li>Organise a project team</li><li>Define parameters (objectives, scope)</li><li>Establish framework (how team operates)</li></ul>",
        critical: false
    },
    {
        question: "What are the 3 steps for organising a project team?",
        answer: "<ol><li>Identify a <strong>sponsor</strong></li><li>Appoint a <strong>project manager (PM)</strong></li><li>Identify <strong>core team</strong> (max 7 members)</li></ol>",
        critical: false
    },
    {
        question: "What are the key responsibilities of a project sponsor?",
        answer: "<ul><li>Appoint project manager</li><li>Set strategic direction</li><li>Approve plan and budget</li><li>Support team members</li><li>Approve project changes</li><li>Set priorities and resolve conflicts</li></ul>",
        critical: false
    },
    {
        question: "What are the key responsibilities of a project manager?",
        answer: "<ul><li>Define project management process</li><li>Prepare and obtain approval of project plan</li><li>Ensure team understands responsibilities</li><li>Expend resources according to plan</li><li>Analyse actual vs planned performance</li><li>Establish priorities</li><li>Provide status reports</li><li>Resolve conflicts</li></ul>",
        critical: false
    },
    {
        question: "What is the maximum recommended size for a core project team?",
        answer: "<h3>At most 7 members</h3><p>Core members make major decisions; extended members provide specific expertise (no limit).</p>",
        critical: false
    },
    {
        question: "Name 5 reasons why projects are authorized.",
        answer: "<ol><li><strong>Technology advances</strong> (e.g., efficient car for gas shortage)</li><li><strong>Social needs</strong> (e.g., new substation for industrial park)</li><li><strong>Market demands</strong> (e.g., new video game player)</li><li><strong>Business needs</strong> (e.g., toxic material guidelines)</li><li><strong>Customer requests</strong> (e.g., portable water project)</li></ol>",
        critical: false
    },
    {
        question: "What does SWOT stand for and what is its purpose?",
        answer: "<ul><li><strong>S</strong>trengths</li><li><strong>W</strong>eaknesses</li><li><strong>O</strong>pportunities</li><li><strong>T</strong>hreats</li></ul><p><strong>Purpose:</strong> Identify suitable projects by analyzing internal capabilities and external factors.</p>",
        critical: false
    },
    {
        question: "What should a Project Objective Statement include?",
        answer: "<ul><li><strong>What</strong> you are going to do (scope)</li><li><strong>By when</strong> (schedule)</li><li><strong>With how many</strong> (resources/costs)</li></ul><p><strong>Max 25 words, only 1 target, clear and precise</strong></p><p>Example: Implement integrated employee database by 31 Dec 2006 with budget of S$20 million.</p>",
        critical: false
    },
    {
        question: "What are the 3 flexibility levels in a Flexibility Matrix?",
        answer: "<ol><li><strong>Least Flexible</strong> cannot be exceeded</li><li><strong>Moderately Flexible</strong> can be adjusted within project objective</li><li><strong>Most Flexible</strong> management willing to exceed original goal if necessary</li></ol><p>Used to determine trade-offs among scope, schedule, and resources.</p>",
        critical: false
    },
    {
        question: "What is the purpose of a List of Major Deliverables?",
        answer: "<ul><li>Defines what the project <strong>is expected to produce</strong></li><li>Provides scope and boundaries</li><li>Reduces rework cycle</li></ul>",
        critical: false
    },
    {
        question: "What is a Project Charter and what does it contain?",
        answer: "<p><strong>Definition:</strong> A document that formally authorizes a project and gives PM authority.</p><p><strong>Contains:</strong></p><ul><li>Project title and description</li><li>PM assigned and authority level</li><li>Project objective statement</li><li>Business case (why?)</li><li>Product description/deliverables</li></ul>",
        critical: false
    },
    {
        question: "What 4 areas should a project framework encompass?",
        answer: "<ol><li><strong>Planning</strong> (what tools, who develops plan)</li><li><strong>Tracking</strong> (meetings, progress assessment)</li><li><strong>Practices</strong> (project file, change approval)</li><li><strong>Relationships</strong> (communication, conflict resolution)</li></ol>",
        critical: false
    },
    {
        question: "What are the key activities in Project Planning?",
        answer: "<ol><li>Develop <strong>Work Breakdown Structure (WBS)</strong></li><li>Approximate <strong>duration of tasks</strong></li><li>Generate <strong>Gantt Chart</strong></li></ol>",
        critical: false
    },
    {
        question: "What is a Work Breakdown Structure (WBS)?",
        answer: "<p>A tool for identifying and presenting project work in a <strong>hierarchical and logically structured manner</strong>.</p><p><strong>Purpose:</strong> Ensure all work required to meet objectives is properly identified, defined, and assigned.</p>",
        critical: false
    },
    {
        question: "What are the 4 key elements of WBS?",
        answer: "<ol><li>Sequence is <strong>NOT</strong> important</li><li>Completeness <strong>IS</strong> important</li><li>Verb/noun symbolizes task & activity</li><li>Each breakdown needs minimum of <strong>2 tasks</strong></li></ol>",
        critical: false
    },
    {
        question: "What approach is used to develop a WBS?",
        answer: "<p><strong>Top-down approach:</strong></p><ol><li>Identify 4 to 7 major components</li><li>Group by: product deliverables, life cycle phases, functional responsibilities, or geographical location</li><li>Validate using <strong>bottom-up approach</strong></li><li>WBS is a <strong>team process</strong> (not PM alone)</li></ol>",
        critical: false
    },
    {
        question: "Who assigns the duration of tasks in a project?",
        answer: "<p>Durations are assigned by the <strong>owners</strong> of the tasks (not the PM).</p><p><strong>Key principles:</strong></p><ul><li>Avoid padding use most likely duration</li><li>Document all assumptions</li><li>Document number of persons and training requirements</li></ul>",
        critical: false
    },
    {
        question: "Explain the relationship: Effort Duration Calendar Time",
        answer: "<ul><li><strong>Effort</strong> total work required (person-hours); for charging purposes</li><li><strong>Duration</strong> time to complete task; for schedule purposes (considers productivity & wait time)</li><li><strong>Calendar Time</strong> real elapsed time; for tracking (considers non-working days, weekends, holidays)</li></ul><p><strong>Formula:</strong> Effort divided by Resources equals Duration times Resource Availability equals Calendar Time</p>",
        critical: false
    },
    {
        question: "What is a Gantt Chart and what is its purpose?",
        answer: "<p><strong>Definition:</strong> A simple representation of a project showing time taken and resources required for each activity.</p><p><strong>Purpose:</strong></p><ul><li>Useful <strong>communication tool</strong></li><li>Easy to understand</li><li>Provides overview of responsibility and progress</li></ul>",
        critical: false
    },
    {
        question: "What are the 4 main activities in Project Execution, Monitoring & Control?",
        answer: "<ol><li><strong>Monitor</strong> the environment (collect info & update status)</li><li><strong>Manage</strong> change (analyze variance)</li><li><strong>Track</strong> progress (take adaptive action)</li><li><strong>Communicate</strong> progress (report status)</li></ol>",
        critical: false
    },
    {
        question: "What is variance in project management?",
        answer: "<p>When actual activities <strong>deviate from planned activities</strong>.</p><p>After identifying causes and impacts, the PM must plan for <strong>adaptive action</strong>.</p>",
        critical: false
    },
    {
        question: "What should you do when planning for adaptive action?",
        answer: "<ul><li>Involve team members in planning</li><li>Review project change control process</li><li>Re-visit all assumptions (schedule, resource, scope)</li><li>Check status data for accuracy</li><li>Implement contingency plan</li><li>Hold key milestones while re-arranging tasks</li><li>Re-plan/re-estimate schedule or resources</li></ul>",
        critical: false
    },
    {
        question: "What should you do when taking adaptive action?",
        answer: "<ul><li>Implement new plan</li><li>Communicate changes to team</li><li>Get buy-in from project team</li><li>Document all changes</li></ul><p><strong>Remember:</strong> Changes in one aspect (scope/schedule/resource) <strong>will affect others</strong> monitor carefully!</p>",
        critical: false
    },
    {
        question: "How often should project status be reported and what should be included?",
        answer: "<p><strong>Frequency:</strong> At least <strong>once a month</strong></p><p><strong>Include:</strong></p><ul><li>Overall % of completion (emphasize milestones)</li><li>Major tasks completed this period</li><li>Project analysis, variance, and adaptive action</li><li>Major tasks for next period</li><li>Outstanding issues (updated schedules, milestones, costs)</li></ul>",
        critical: false
    },
    {
        question: "What are the key considerations before project closure?",
        answer: "<ul><li><strong>Announce</strong> end of project</li><li><strong>Conduct</strong> final project review</li><li><strong>Debrief</strong> key learning</li><li><strong>Deliver</strong> acknowledgements and rewards</li><li><strong>Closing ritual</strong> (celebration)</li><li><strong>Complete paperwork</strong> (contract, payment, schedule, lessons learned, close file)</li></ul>",
        critical: false
    },
    {
        question: "What is the purpose of conducting a project review?",
        answer: "<ul><li>Highlight <strong>what went right AND what went wrong</strong></li><li>Purpose is <strong>NOT finger pointing</strong> but to minimize future problems</li><li>Essential for <strong>continuous improvement</strong></li><li>Identify success elements</li><li>Avoid future problems</li><li><strong>Capture key learning</strong> for future projects</li></ul>",
        critical: false
    },
    {
        question: "What steps are involved in closing the project file?",
        answer: "<ul><li>Complete all final review documents</li><li>Bundle and label all status reports</li><li>Send all project files for archiving</li><li><strong>PM is responsible</strong> for ensuring proper storage</li></ul>",
        critical: false
    }
];
