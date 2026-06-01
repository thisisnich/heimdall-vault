---
tags:
  - obsidian-skills
  - patterns
  - workflow
  - productivity
type: Guide
created: 2026-05-19
status: Active
---

# Obsidian Skills - Practical Patterns

> 🛠️ **Kepano's Obsidian Skills** — Practical vault workflows and patterns
> 🎯 **Focus:** Efficient navigation, organization, and knowledge building

---

## 🔄 Core Navigation Patterns

### Quick Navigation
**Command Palette (Ctrl/Cmd + P):**
- **Quick Switch:** `Ctrl/Cmd + O` → Switch between files
- **Quick Add:** `Ctrl/Cmd + N` → Create new note
- **Command Search:** Type any command name
- **File Search:** `Ctrl/Cmd + Shift + F`

**Smart Navigation:**
- **Go Back:** `Ctrl/Cmd + Alt + ←`  
- **Go Forward:** `Ctrl/Cmd + Alt + →`
- **Split View:** `Ctrl/Cmd + \` → Horizontal split
- **New Tab:** `Ctrl/Cmd + T`

---

## 📝 Note Creation Patterns

### Template Usage
**Daily Note Template:**
```markdown
---
date: {{date}}
mood: 
focus: 
tags: [daily]
---

# {{date}}

## 🎯 Today's Focus
- 

## 📝 Key Learnings
- 

## 🔗 Connections
- 

## 📅 Tomorrow's Plan
- 

## 💭 Reflections
- 
```

**Project Note Template:**
```markdown
---
project: 
status: active
deadline: 
tags: [project, active]
---

# {{title}}

## 🎯 Objectives
- 

## 📋 Tasks
- [ ] 

## 📊 Progress
**Current:** 
**Target:** 

## 🔗 Resources
- 

## 📝 Notes
- 
```

### Quick Capture Patterns
**Zettelkasten-style:**
- One idea per note
- Atomic notes (single concept)
- Rich linking
- Permanent notes vs fleeting notes

**Progressive Summarization:**
1. **Bold key points** during first pass
2. **Highlight** important sections on second pass
3. **Create summary** at top on third pass

---

## 🔗 Linking Strategies

### Link Types
**Internal Links:**
- **Contextual:** `[[Concept]]` within sentences
- **Reference:** `[[Concept|Display Text]]` custom display
- **Block Links:** `[[Note#^block-id]]` specific blocks
- **Header Links:** `[[Note#Header]]` specific sections

**External Links:**
- **Web:** `[Text](URL)` standard markdown
- **Obsidian URI:** `obsidian://open?file=Note` vault links
- **File Links:** `[[file:/path/to/file]]` local files

### Link Building Habits
**When Creating Notes:**
1. **Link existing concepts** as you write
2. **Create placeholder links** for future notes: `[[Future Concept]]`
3. **Use descriptive link text**: `[[EGE320|Embedded Systems]]`
4. **Add context**: Why this link matters

**During Review:**
1. **Find orphan notes** (no backlinks)
2. **Strengthen weak connections**
3. **Create hub notes** for related topics
4. **Add bidirectional links**

---

## 🗂️ Organization Patterns

### Folder Structure Best Practices
**PARA Implementation:**
```
📁 Projects/          # Active projects with deadlines
📁 Areas/            # Ongoing responsibilities  
📁 Resources-RAW/     # Reference materials
📁 03-RESOURCES/     # Structured academic content
📁 04-ARCHIVE/       # Completed/inactive content
📁 Resources-RAW/
  📁 inbox/          # Raw capture
```

**Naming Conventions:**
- **Dates:** `YYYY-MM-DD` format for sorting
- **Projects:** `Project Name - Status`
- **Topics:** `Topic - Subtopic`
- **Consistent:** Use same pattern throughout

### Tag Systems
**Hierarchical Tags:**
- `#academic/egexxx` for courses
- `#project/active/project-name` for projects
- `#status/active|completed|archived` for status
- `#type/note|resource|task` for content type

**Tag Usage Rules:**
- **Be specific** rather than general
- **Use consistent** naming
- **Limit to 3-5 tags** per note
- **Review regularly** for cleanup

---

## 🔍 Search & Discovery Patterns

### Search Techniques
**Basic Search:**
- **Simple:** `keyword` finds all matches
- **Exact:** `"exact phrase"` for precise matches
- **Exclude:** `keyword -exclude` removes terms
- **OR:** `keyword1 OR keyword2` broadens search

**Advanced Search:**
- **Path:** `path:"folder"` search specific folders
- **File:** `file:"filename"` search file names
- **Tag:** `tag:#specific-tag` search tags
- **Content:** `content:"text"` search within notes

### Discovery Methods
**Graph View Navigation:**
- **Filter by tag** to see related clusters
- **Local view** for current note context
- **Group by folder** for organization view
- **Search nodes** to find specific topics

**Backlink Exploration:**
- **Check backlinks** regularly
- **Follow link chains** for deep dives
- **Discover unexpected connections**
- **Identify knowledge gaps**

---

## 📊 Productivity Patterns

### Daily Workflow
**Morning Setup (5 min):**
1. Open [[02-DAILY/Daily Note|today's daily note]]
2. Review [[Resources-RAW/inbox/|inbox]] for urgent items
3. Check [[📅 Schedule & Assessments Dashboard|schedule]] for deadlines
4. Set [[Projects/Projects - Index|project priorities]]

**Throughout Day:**
- **Quick capture** to [[Resources-RAW/inbox/|inbox]]
- **Link as you go** when creating notes
- **Use command palette** for efficiency
- **Split view** for reference while writing

**Evening Review (10 min):**
1. Process [[Resources-RAW/inbox/|inbox]] items
2. Update [[Projects/Projects - Index|project progress]]
3. Create tomorrow's [[02-DAILY/Daily Note|daily note]]
4. Quick [[Areas/Areas - Index|area check-in]]

### Weekly Review
**Friday Review (30-60 min):**
1. **Inbox cleanup** - Process remaining items
2. **Project status** - Update all active projects
3. **Knowledge synthesis** - Create structured notes
4. **Link building** - Strengthen connections
5. **Archive management** - Move completed items
6. **Next week planning** - Set priorities

---

## 🎯 Advanced Patterns

### Knowledge Synthesis
**MOC (Map of Content) Creation:**
1. **Identify topic clusters** through graph view
2. **Create hub notes** for related concepts
3. **Add structure** with headers and sections
4. **Link bidirectionally** to all related notes
5. **Maintain regularly** as content grows

**Progressive Summarization:**
1. **First Pass:** Bold key points while reading
2. **Second Pass:** Highlight most important bolded points  
3. **Third Pass:** Create summary at top with key insights
4. **Fourth Pass:** Extract actionable items

### Automation Patterns
**Templates for Consistency:**
- **Daily notes** with consistent structure
- **Project notes** with standard fields
- **Meeting notes** with action items
- **Research notes** with source tracking

**Quick Commands:**
- **Create daily note:** Custom command with template
- **Process inbox:** Command to open inbox + daily note
- **Weekly review:** Command to open all review files
- **Project dashboard:** Command to show active projects

---

## 🛠️ Plugin Integration

### Essential Plugins
**Core Functionality:**
- **Tag Wrangler:** Bulk tag management
- **Quick Switcher:** Fast file navigation
- **Command Palette:** Enhanced command search
- **Workspaces:** Save window configurations

**Advanced Features:**
- **Dataview:** Dynamic content and queries
- **Calendar:** Visual date navigation
- **Kanban:** Task management boards
- **Excalidraw:** Visual diagrams and sketches

### Plugin Workflows
**Task Management:**
- Use **Kanban** for project tracking
- **Dataview** for dynamic task lists
- **Calendar** for deadline visualization
- **Tags** for task categorization

**Knowledge Building:**
- **Graph view** for connection discovery
- **Quick switcher** for fast navigation
- **Command palette** for efficiency
- **Workspaces** for context switching

---

## 💡 Pro Tips

### Efficiency Hacks
- **Keyboard shortcuts** over mouse navigation
- **Command palette** for most actions
- **Templates** for consistent structure
- **Quick capture** to avoid breaking flow

### Quality Maintenance
- **Regular reviews** to prevent clutter
- **Link auditing** to find orphan notes
- **Tag cleanup** to maintain organization
- **Archive management** to keep current focus

### Knowledge Building
- **One idea per note** for atomic concepts
- **Rich linking** for knowledge networks
- **Regular synthesis** for deeper understanding
- **Progressive summarization** for retention

---

## 🔗 Quick Reference

### Essential Shortcuts
- `Ctrl/Cmd + P` - Command Palette
- `Ctrl/Cmd + O` - Quick Switcher
- `Ctrl/Cmd + Shift + O` - Quick Add
- `Ctrl/Cmd + G` - Open graph view
- `Ctrl/Cmd + E` - Toggle edit/preview
- `Ctrl/Cmd + [` - Fold/unfold

### Workflow Commands
- `Daily Note` - Create today's note
- `Process Inbox` - Open inbox for review
- `Project Dashboard` - Show active projects
- `Weekly Review` - Start review process

### Search Operators
- `"phrase"` - Exact phrase search
- `-exclude` - Exclude terms
- `tag:#tag` - Search by tag
- `path:"folder"` - Search in folder
- `file:name` - Search filename

---

*Last updated: 19 May 2026*  
*Based on Kepano's Obsidian Skills patterns*  
*Adapted for Lazy Method implementation*
