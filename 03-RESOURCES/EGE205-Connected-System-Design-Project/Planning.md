# Green Tech Project Planning Document
## BeagleBone Black Wireless Sustainable Solution

---
[[EGE205 User And Data Collection (Project Report Part 1) Week 2.pdf|Decision Slides]]
[[CSDP Plannign slides|Decision Slides as md]]
## 1. Understanding Phase
### Driving Question: Green/Sustainable/Livable Solutions

#### Problem Identification
- **Where is the problem?**
  - [ ] Urban environments with poor air quality monitoring
  - [ ] Rural areas lacking environmental data collection
  - [ ] Industrial zones needing real-time pollution tracking
  - [ ] Residential areas requiring energy efficiency monitoring
  - [ ] Agricultural regions needing soil/weather monitoring
  - [x] **Community recycling centers with contamination issues**
  - [ ] **Community centers and commercial buildings with inefficient resource usage**
  - [ ] Other: ________________

##### **Problem 1: Smart Recycling Assistant - "What Goes Where?"**
- **Problem Statement:** People frequently dispose of recyclables in wrong bins (cardboard in e-waste, books in general waste) due to confusing recycling guidelines and lack of clear guidance
- **Impact:** High contamination rates, reduced recycling effectiveness, people avoid recycling because it's "too difficult"
- **Target Locations:** Community recycling centers, residential areas, commercial buildings
- **Solution Approach:** **Automated Sorting System** - Uses Google Cloud AI Vision API with BeagleBone Black Wireless to identify waste items and automatically sort them into correct bins
- **User Pain Points:**
  - [ ] Unclear recycling guidelines
  - [ ] Inconsistent rules across different areas
  - [ ] Fear of "doing it wrong"
  - [ ] Lack of immediate feedback on proper disposal
  - [ ] No educational component for learning
  - [x] **Manual sorting is time-consuming and error-prone**
  - [x] **Users don't want to learn complex sorting rules**

##### **Problem 2: Community Water & Energy Monitoring Hub**
- **Problem Statement:** Community centers and commercial buildings waste water and energy due to lack of real-time monitoring and awareness of resource consumption patterns
- **Impact:** Unnecessary resource waste, higher operational costs, missed opportunities for efficiency improvements
- **Target Locations:** Community centers, small commercial buildings, educational institutions
- **User Pain Points:**
  - [ ] No visibility into real-time resource usage
  - [ ] Expensive monitoring systems out of reach for small communities
  - [ ] Difficulty identifying which areas/activities consume most resources
  - [ ] No alerts for leaks or unusual usage patterns
  - [ ] Lack of data to make informed efficiency decisions

#### Customer/User Analysis

##### User Segmentation Framework (STP Approach)

**1. Demographic Segmentation (B2C)**
- **Age:** 
  - [ ] 18-25 (Students, young professionals)
  - [ ] 26-40 (Working professionals, homeowners)
  - [ ] 41-60 (Established professionals, facility managers)
  - [ ] 60+ (Retirees, community leaders)
- **Gender:** 
  - [ ] Male
  - [ ] Female
  - [ ] Non-binary/Other
- **Income Level:**
  - [ ] Low income (<$30k)
  - [ ] Middle income ($30k-$75k)
  - [ ] High income ($75k+)
- **Education Level:**
  - [ ] High school or less
  - [ ] College/University
  - [ ] Graduate/Professional degree
- **Profession/Role:**
  - [ ] Environmental researchers
  - [ ] City planners and officials
  - [ ] Homeowners seeking energy efficiency
  - [ ] Farmers and agricultural workers
  - [ ] Industrial facility managers
  - [ ] Community activists
  - [ ] Students and educators
  - [ ] Other: ________________

**2. Demographic Segmentation (B2B)**
- **Company Size:**
  - [ ] Small business (1-50 employees)
  - [ ] Medium business (51-200 employees)
  - [ ] Large enterprise (200+ employees)
- **Industry:**
  - [ ] Government/Municipal
  - [ ] Agriculture
  - [ ] Manufacturing
  - [ ] Education
  - [ ] Healthcare
  - [ ] Real Estate
  - [ ] Other: ________________
- **Operating Hours:**
  - [ ] 24/7 operations
  - [ ] Business hours only
  - [ ] Seasonal operations
- **Business Model:**
  - [ ] Public sector
  - [ ] Private sector
  - [ ] Non-profit
  - [ ] Research institutions

**3. Geographic Segmentation**
- **Country/Region:**
  - [ ] Singapore (Primary)
  - [ ] Southeast Asia
  - [ ] Other: ________________
- **Urban vs Rural:**
  - [ ] Urban areas (high population density)
  - [ ] Suburban areas
  - [ ] Rural areas
- **Climate Zone:**
  - [ ] Tropical
  - [ ] Temperate
  - [ ] Other: ________________

**4. Psychographic Segmentation**
- **Personality Traits:**
  - [ ] Tech-savvy early adopters
  - [ ] Environmentally conscious
  - [ ] Data-driven decision makers
  - [ ] Community-oriented
- **Values & Beliefs:**
  - [ ] Environmental sustainability
  - [ ] Cost efficiency
  - [ ] Innovation and technology
  - [ ] Community welfare
- **Lifestyle:**
  - [ ] Urban professionals
  - [ ] Rural/agricultural workers
  - [ ] Academic/research focused
  - [ ] Community activists

**5. Behavioral Segmentation**
- **Technology Adoption:**
  - [ ] Early adopters
  - [ ] Early majority
  - [ ] Late majority
  - [ ] Laggards
- **Spending Habits:**
  - [ ] Budget-conscious
  - [ ] Value-oriented
  - [ ] Premium seekers
- **Interaction Patterns:**
  - [ ] Hands-on users
  - [ ] Passive monitoring
  - [ ] Data analysis focused
  - [ ] Alert-driven users

##### User Group Decision Matrix

| Criteria | Weight | User Group 1 | User Group 2 | User Group 3 | User Group 4 |
|----------|--------|--------------|--------------|--------------|--------------|
| **Reachable** (Accessible via available platforms) | 25% | Score: ___ | Score: ___ | Score: ___ | Score: ___ |
| **Sizeable** (Large enough customer base) | 20% | Score: ___ | Score: ___ | Score: ___ | Score: ___ |
| **Affordable** (Sufficient purchasing power) | 20% | Score: ___ | Score: ___ | Score: ___ | Score: ___ |
| **Receptive** (Willing to adopt new technology) | 15% | Score: ___ | Score: ___ | Score: ___ | Score: ___ |
| **Perceptible Needs** (Clear problems/needs) | 20% | Score: ___ | Score: ___ | Score: ___ | Score: ___ |
| **Total Weighted Score** | 100% | **___** | **___** | **___** | **___** |

*Scoring: 1-5 scale (1=Poor, 5=Excellent)*

##### Selected Target User Group
**Primary Target:** ________________
**Secondary Target:** ________________

**Rationale for Selection:**
```
[Explain why this user group was selected based on the decision matrix]
```

##### User Needs Analysis
- **Functional Needs:**
  - [ ] Real-time environmental data
  - [ ] Historical trend analysis
  - [ ] Automated alerts and notifications
  - [ ] Remote monitoring capabilities
  - [ ] Data visualization and reporting
  - [ ] Other: ________________

- **Emotional Needs:**
  - [ ] Peace of mind about environmental conditions
  - [ ] Sense of control over environment
  - [ ] Community contribution feeling
  - [ ] Cost savings satisfaction
  - [ ] Other: ________________

- **Technical Requirements:**
  - [ ] Easy-to-understand interfaces
  - [ ] Mobile accessibility
  - [ ] Reliable data accuracy
  - [ ] Low maintenance requirements
  - [ ] Other: ________________

#### Solution Definition
- **Core Solution Concept:**
  ```
  [Describe your main solution idea here]
  ```

- **Key Features:**
  - [ ] Environmental sensor integration
  - [ ] Wireless data transmission
  - [ ] Web-based dashboard
  - [ ] Mobile app interface
  - [ ] Automated reporting
  - [ ] Alert system
  - [ ] Data visualization
  - [ ] Other: ________________

- **Success Criteria:**
  - [ ] Measurable environmental impact
  - [ ] User adoption rate
  - [ ] Data accuracy and reliability
  - [ ] Cost-effectiveness
  - [ ] Scalability
  - [ ] Other: ________________

---

## 2. Development Phase
### BeagleBone Black Wireless Implementation

#### Hardware Requirements
- **Core Platform:** BeagleBone Black Wireless
- **Sensors Needed:**
  - [ ] Temperature sensor (TMP102)
  - [ ] Humidity sensor (Si7021)
  - [ ] Air quality sensor
  - [ ] Light sensor
  - [ ] Motion sensor (PIR)
  - [ ] Ultrasonic distance sensor
  - [ ] Pressure sensor (BMP085)
  - [ ] Other: ________________

- **Additional Components:**
  - [ ] LEDs for status indication
  - [ ] Servo motors for automated systems
  - [ ] Display (LCD/OLED)
  - [ ] Power management
  - [ ] Enclosure/casing
  - [ ] Other: ________________

#### Software Development
- **Programming Languages:**
  - [ ] JavaScript (Node.js/BoneScript)
  - [ ] Python
  - [ ] C/C++ for PRU
  - [ ] HTML/CSS/JavaScript for web interface
  - [ ] Other: ________________

- **Key Libraries/Frameworks:**
  - [ ] BoneScript for hardware control
  - [ ] Express.js for web server
  - [ ] Socket.io for real-time communication
  - [ ] Chart.js for data visualization
  - [ ] Other: ________________

#### Development Milestones
- [ ] **Week 1-2:** Basic sensor integration
- [ ] **Week 3-4:** Data collection and storage
- [ ] **Week 5-6:** Web interface development
- [ ] **Week 7-8:** Wireless communication setup
- [ ] **Week 9-10:** Testing and optimization
- [ ] **Week 11-12:** Documentation and deployment prep

---

## 3. Integration Phase
### System Integration and Connectivity

#### Hardware Integration
- [ ] Sensor wiring and connections
- [ ] Power supply optimization
- [ ] Enclosure design and fabrication
- [ ] Weatherproofing considerations
- [ ] Mounting and installation planning

#### Software Integration
- [ ] Database setup (SQLite/PostgreSQL)
- [ ] API development
- [ ] Web server configuration
- [ ] Mobile app integration
- [ ] Cloud service integration

#### Communication Protocols
- [ ] WiFi connectivity
- [ ] Bluetooth integration
- [ ] Cellular backup (if needed)
- [ ] MQTT for IoT communication
- [ ] REST API endpoints
- [ ] WebSocket for real-time data

#### Data Flow Architecture
```
[Sensors] → [BeagleBone] → [Local Processing] → [Web Interface]
     ↓
[Database] ← [Cloud Services] ← [Mobile App]
```

---

## 4. Trial Phase
### Testing and Validation

#### Testing Strategy
- **Unit Testing:**
  - [ ] Individual sensor functionality
  - [ ] Data processing algorithms
  - [ ] Web interface components
  - [ ] API endpoints

- **Integration Testing:**
  - [ ] End-to-end data flow
  - [ ] Wireless communication reliability
  - [ ] Power consumption optimization
  - [ ] Error handling and recovery

- **Field Testing:**
  - [ ] Real-world environmental conditions
  - [ ] Long-term stability testing
  - [ ] User acceptance testing
  - [ ] Performance benchmarking

#### Validation Metrics
- [ ] Data accuracy (±X% tolerance)
- [ ] Uptime reliability (>99%)
- [ ] Response time (<X seconds)
- [ ] Power efficiency (X days battery life)
- [ ] User satisfaction score
- [ ] Environmental impact measurement

#### Pilot Deployment
- **Location:** ________________
- **Duration:** ________________
- **Participants:** ________________
- **Success Criteria:** ________________

---

## 5. Connected Solution Phase
### Deployment and Scaling

#### Production Deployment
- [ ] Manufacturing considerations
- [ ] Supply chain management
- [ ] Quality assurance processes
- [ ] Installation procedures
- [ ] User training materials

#### Monitoring and Maintenance
- [ ] Remote monitoring system
- [ ] Automated diagnostics
- [ ] Predictive maintenance
- [ ] Software update mechanisms
- [ ] Technical support structure

#### Scaling Strategy
- [ ] Multi-site deployment
- [ ] Cloud infrastructure scaling
- [ ] Data analytics platform
- [ ] Machine learning integration
- [ ] Community engagement

#### Business Model
- [ ] Revenue streams
- [ ] Pricing strategy
- [ ] Partnership opportunities
- [ ] Market expansion plans
- [ ] Sustainability metrics

---

## Technology Stack (To Be Completed)
*[User mentioned they will share the rest of the tech stack later]*

### Current Stack:
- **Hardware:** BeagleBone Black Wireless
- **Development Environment:** Cloud9 IDE
- **Programming:** Python (current focus)

### Additional Stack Components:
- [ ] Database: ________________
- [x] **Cloud Platform: Google Cloud Platform**
- [x] **AI/ML Service: Google Cloud AI Vision API**
- [ ] Mobile Framework: ________________
- [ ] Analytics Tools: ________________
- [ ] Other: ________________

---

## Next Steps
1. [ ] Complete problem identification and user analysis
2. [ ] Define specific solution requirements
3. [ ] Select sensors and additional hardware
4. [ ] Begin development with basic sensor integration
5. [ ] Plan integration architecture
6. [ ] Design testing protocols

---

## Notes and Ideas
*[Space for additional thoughts, research, and brainstorming]*

---

*Last Updated: [Date]*
*Project Status: Planning Phase*
