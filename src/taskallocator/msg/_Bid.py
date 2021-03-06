"""autogenerated by genpy from taskallocator/Bid.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import taskallocator.msg
import std_msgs.msg

class Bid(genpy.Message):
  _md5sum = "a98846b1135a183a1abeeff5b916c6b2"
  _type = "taskallocator/Bid"
  _has_header = True #flag to mark the presence of a Header object
  _full_text = """Header header
Task task
uint32 ID
float32 bidCost

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.secs: seconds (stamp_secs) since epoch
# * stamp.nsecs: nanoseconds since stamp_secs
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: taskallocator/Task
Header header
Instruction[] instructions

================================================================================
MSG: taskallocator/Instruction
Header header

#determines type of instruction
bool reqsHumanHelp

#standardized set of descriptors for different human interactions (eventually)
#extraneous if reqsHumanHelp is false
#not yet implemented (only goto is right now) 
string helpDescriptor

#all fields below are only for goto commands
#extraneous if reqsHumanHelp is true
uint32 startFloor
float32 startX
float32 startY

uint32 endFloor
float32 endX
float32 endY

"""
  __slots__ = ['header','task','ID','bidCost']
  _slot_types = ['std_msgs/Header','taskallocator/Task','uint32','float32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       header,task,ID,bidCost

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(Bid, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.task is None:
        self.task = taskallocator.msg.Task()
      if self.ID is None:
        self.ID = 0
      if self.bidCost is None:
        self.bidCost = 0.
    else:
      self.header = std_msgs.msg.Header()
      self.task = taskallocator.msg.Task()
      self.ID = 0
      self.bidCost = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_3I.pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_3I.pack(_x.task.header.seq, _x.task.header.stamp.secs, _x.task.header.stamp.nsecs))
      _x = self.task.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      length = len(self.task.instructions)
      buff.write(_struct_I.pack(length))
      for val1 in self.task.instructions:
        _v1 = val1.header
        buff.write(_struct_I.pack(_v1.seq))
        _v2 = _v1.stamp
        _x = _v2
        buff.write(_struct_2I.pack(_x.secs, _x.nsecs))
        _x = _v1.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        buff.write(_struct_B.pack(val1.reqsHumanHelp))
        _x = val1.helpDescriptor
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _x = val1
        buff.write(_struct_I2fI2f.pack(_x.startFloor, _x.startX, _x.startY, _x.endFloor, _x.endX, _x.endY))
      _x = self
      buff.write(_struct_If.pack(_x.ID, _x.bidCost))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.task is None:
        self.task = taskallocator.msg.Task()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _struct_3I.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 12
      (_x.task.header.seq, _x.task.header.stamp.secs, _x.task.header.stamp.nsecs,) = _struct_3I.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.task.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.task.header.frame_id = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.task.instructions = []
      for i in range(0, length):
        val1 = taskallocator.msg.Instruction()
        _v3 = val1.header
        start = end
        end += 4
        (_v3.seq,) = _struct_I.unpack(str[start:end])
        _v4 = _v3.stamp
        _x = _v4
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _struct_2I.unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v3.frame_id = str[start:end].decode('utf-8')
        else:
          _v3.frame_id = str[start:end]
        start = end
        end += 1
        (val1.reqsHumanHelp,) = _struct_B.unpack(str[start:end])
        val1.reqsHumanHelp = bool(val1.reqsHumanHelp)
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.helpDescriptor = str[start:end].decode('utf-8')
        else:
          val1.helpDescriptor = str[start:end]
        _x = val1
        start = end
        end += 24
        (_x.startFloor, _x.startX, _x.startY, _x.endFloor, _x.endX, _x.endY,) = _struct_I2fI2f.unpack(str[start:end])
        self.task.instructions.append(val1)
      _x = self
      start = end
      end += 8
      (_x.ID, _x.bidCost,) = _struct_If.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_3I.pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_struct_3I.pack(_x.task.header.seq, _x.task.header.stamp.secs, _x.task.header.stamp.nsecs))
      _x = self.task.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      length = len(self.task.instructions)
      buff.write(_struct_I.pack(length))
      for val1 in self.task.instructions:
        _v5 = val1.header
        buff.write(_struct_I.pack(_v5.seq))
        _v6 = _v5.stamp
        _x = _v6
        buff.write(_struct_2I.pack(_x.secs, _x.nsecs))
        _x = _v5.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        buff.write(_struct_B.pack(val1.reqsHumanHelp))
        _x = val1.helpDescriptor
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _x = val1
        buff.write(_struct_I2fI2f.pack(_x.startFloor, _x.startX, _x.startY, _x.endFloor, _x.endX, _x.endY))
      _x = self
      buff.write(_struct_If.pack(_x.ID, _x.bidCost))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.task is None:
        self.task = taskallocator.msg.Task()
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _struct_3I.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 12
      (_x.task.header.seq, _x.task.header.stamp.secs, _x.task.header.stamp.nsecs,) = _struct_3I.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.task.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.task.header.frame_id = str[start:end]
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.task.instructions = []
      for i in range(0, length):
        val1 = taskallocator.msg.Instruction()
        _v7 = val1.header
        start = end
        end += 4
        (_v7.seq,) = _struct_I.unpack(str[start:end])
        _v8 = _v7.stamp
        _x = _v8
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _struct_2I.unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v7.frame_id = str[start:end].decode('utf-8')
        else:
          _v7.frame_id = str[start:end]
        start = end
        end += 1
        (val1.reqsHumanHelp,) = _struct_B.unpack(str[start:end])
        val1.reqsHumanHelp = bool(val1.reqsHumanHelp)
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.helpDescriptor = str[start:end].decode('utf-8')
        else:
          val1.helpDescriptor = str[start:end]
        _x = val1
        start = end
        end += 24
        (_x.startFloor, _x.startX, _x.startY, _x.endFloor, _x.endX, _x.endY,) = _struct_I2fI2f.unpack(str[start:end])
        self.task.instructions.append(val1)
      _x = self
      start = end
      end += 8
      (_x.ID, _x.bidCost,) = _struct_If.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_B = struct.Struct("<B")
_struct_3I = struct.Struct("<3I")
_struct_I2fI2f = struct.Struct("<I2fI2f")
_struct_2I = struct.Struct("<2I")
_struct_If = struct.Struct("<If")
