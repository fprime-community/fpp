# ----------------------------------------------------------------------
# Constants and types
# ----------------------------------------------------------------------

@ Data for a DataRecord
struct Data {
  @ A U16 field
  u16Field: U16
}

# ----------------------------------------------------------------------
# Records
# ----------------------------------------------------------------------

@ Record 1
product record U32Record: U32 id 100

@ Record 2
product record DataRecord: Data id 200

@ Record 3
product record U8ArrayRecord: U8 array id 300

@ Record 4
product record U32ArrayRecord: U32 array id 400

@ Record 5
product record DataArrayRecord: Data array id 500

# ----------------------------------------------------------------------
# Containers
# ----------------------------------------------------------------------

@ Container 1
product container Container1 id 100 default priority 10

@ Container 2
product container Container2 id 200 default priority 20

@ Container 3
product container Container3 id 300

@ Container 4
product container Container4 id 400

@ Container 5
product container Container5 id 500
