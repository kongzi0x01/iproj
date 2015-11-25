// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: header.proto

package protocol;

public final class IprojHeader {
  private IprojHeader() {}
  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistry registry) {
  }
  public interface HeaderOrBuilder
      extends com.google.protobuf.MessageOrBuilder {

    // optional uint64 id = 1;
    /**
     * <code>optional uint64 id = 1;</code>
     */
    boolean hasId();
    /**
     * <code>optional uint64 id = 1;</code>
     */
    long getId();

    // optional string msg_full_name = 2;
    /**
     * <code>optional string msg_full_name = 2;</code>
     */
    boolean hasMsgFullName();
    /**
     * <code>optional string msg_full_name = 2;</code>
     */
    java.lang.String getMsgFullName();
    /**
     * <code>optional string msg_full_name = 2;</code>
     */
    com.google.protobuf.ByteString
        getMsgFullNameBytes();
  }
  /**
   * Protobuf type {@code protocol.Header}
   */
  public static final class Header extends
      com.google.protobuf.GeneratedMessage
      implements HeaderOrBuilder {
    // Use Header.newBuilder() to construct.
    private Header(com.google.protobuf.GeneratedMessage.Builder<?> builder) {
      super(builder);
      this.unknownFields = builder.getUnknownFields();
    }
    private Header(boolean noInit) { this.unknownFields = com.google.protobuf.UnknownFieldSet.getDefaultInstance(); }

    private static final Header defaultInstance;
    public static Header getDefaultInstance() {
      return defaultInstance;
    }

    public Header getDefaultInstanceForType() {
      return defaultInstance;
    }

    private final com.google.protobuf.UnknownFieldSet unknownFields;
    @java.lang.Override
    public final com.google.protobuf.UnknownFieldSet
        getUnknownFields() {
      return this.unknownFields;
    }
    private Header(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      initFields();
      int mutable_bitField0_ = 0;
      com.google.protobuf.UnknownFieldSet.Builder unknownFields =
          com.google.protobuf.UnknownFieldSet.newBuilder();
      try {
        boolean done = false;
        while (!done) {
          int tag = input.readTag();
          switch (tag) {
            case 0:
              done = true;
              break;
            default: {
              if (!parseUnknownField(input, unknownFields,
                                     extensionRegistry, tag)) {
                done = true;
              }
              break;
            }
            case 8: {
              bitField0_ |= 0x00000001;
              id_ = input.readUInt64();
              break;
            }
            case 18: {
              bitField0_ |= 0x00000002;
              msgFullName_ = input.readBytes();
              break;
            }
          }
        }
      } catch (com.google.protobuf.InvalidProtocolBufferException e) {
        throw e.setUnfinishedMessage(this);
      } catch (java.io.IOException e) {
        throw new com.google.protobuf.InvalidProtocolBufferException(
            e.getMessage()).setUnfinishedMessage(this);
      } finally {
        this.unknownFields = unknownFields.build();
        makeExtensionsImmutable();
      }
    }
    public static final com.google.protobuf.Descriptors.Descriptor
        getDescriptor() {
      return protocol.IprojHeader.internal_static_protocol_Header_descriptor;
    }

    protected com.google.protobuf.GeneratedMessage.FieldAccessorTable
        internalGetFieldAccessorTable() {
      return protocol.IprojHeader.internal_static_protocol_Header_fieldAccessorTable
          .ensureFieldAccessorsInitialized(
              protocol.IprojHeader.Header.class, protocol.IprojHeader.Header.Builder.class);
    }

    public static com.google.protobuf.Parser<Header> PARSER =
        new com.google.protobuf.AbstractParser<Header>() {
      public Header parsePartialFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws com.google.protobuf.InvalidProtocolBufferException {
        return new Header(input, extensionRegistry);
      }
    };

    @java.lang.Override
    public com.google.protobuf.Parser<Header> getParserForType() {
      return PARSER;
    }

    private int bitField0_;
    // optional uint64 id = 1;
    public static final int ID_FIELD_NUMBER = 1;
    private long id_;
    /**
     * <code>optional uint64 id = 1;</code>
     */
    public boolean hasId() {
      return ((bitField0_ & 0x00000001) == 0x00000001);
    }
    /**
     * <code>optional uint64 id = 1;</code>
     */
    public long getId() {
      return id_;
    }

    // optional string msg_full_name = 2;
    public static final int MSG_FULL_NAME_FIELD_NUMBER = 2;
    private java.lang.Object msgFullName_;
    /**
     * <code>optional string msg_full_name = 2;</code>
     */
    public boolean hasMsgFullName() {
      return ((bitField0_ & 0x00000002) == 0x00000002);
    }
    /**
     * <code>optional string msg_full_name = 2;</code>
     */
    public java.lang.String getMsgFullName() {
      java.lang.Object ref = msgFullName_;
      if (ref instanceof java.lang.String) {
        return (java.lang.String) ref;
      } else {
        com.google.protobuf.ByteString bs = 
            (com.google.protobuf.ByteString) ref;
        java.lang.String s = bs.toStringUtf8();
        if (bs.isValidUtf8()) {
          msgFullName_ = s;
        }
        return s;
      }
    }
    /**
     * <code>optional string msg_full_name = 2;</code>
     */
    public com.google.protobuf.ByteString
        getMsgFullNameBytes() {
      java.lang.Object ref = msgFullName_;
      if (ref instanceof java.lang.String) {
        com.google.protobuf.ByteString b = 
            com.google.protobuf.ByteString.copyFromUtf8(
                (java.lang.String) ref);
        msgFullName_ = b;
        return b;
      } else {
        return (com.google.protobuf.ByteString) ref;
      }
    }

    private void initFields() {
      id_ = 0L;
      msgFullName_ = "";
    }
    private byte memoizedIsInitialized = -1;
    public final boolean isInitialized() {
      byte isInitialized = memoizedIsInitialized;
      if (isInitialized != -1) return isInitialized == 1;

      memoizedIsInitialized = 1;
      return true;
    }

    public void writeTo(com.google.protobuf.CodedOutputStream output)
                        throws java.io.IOException {
      getSerializedSize();
      if (((bitField0_ & 0x00000001) == 0x00000001)) {
        output.writeUInt64(1, id_);
      }
      if (((bitField0_ & 0x00000002) == 0x00000002)) {
        output.writeBytes(2, getMsgFullNameBytes());
      }
      getUnknownFields().writeTo(output);
    }

    private int memoizedSerializedSize = -1;
    public int getSerializedSize() {
      int size = memoizedSerializedSize;
      if (size != -1) return size;

      size = 0;
      if (((bitField0_ & 0x00000001) == 0x00000001)) {
        size += com.google.protobuf.CodedOutputStream
          .computeUInt64Size(1, id_);
      }
      if (((bitField0_ & 0x00000002) == 0x00000002)) {
        size += com.google.protobuf.CodedOutputStream
          .computeBytesSize(2, getMsgFullNameBytes());
      }
      size += getUnknownFields().getSerializedSize();
      memoizedSerializedSize = size;
      return size;
    }

    private static final long serialVersionUID = 0L;
    @java.lang.Override
    protected java.lang.Object writeReplace()
        throws java.io.ObjectStreamException {
      return super.writeReplace();
    }

    public static protocol.IprojHeader.Header parseFrom(
        com.google.protobuf.ByteString data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static protocol.IprojHeader.Header parseFrom(
        com.google.protobuf.ByteString data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static protocol.IprojHeader.Header parseFrom(byte[] data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static protocol.IprojHeader.Header parseFrom(
        byte[] data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static protocol.IprojHeader.Header parseFrom(java.io.InputStream input)
        throws java.io.IOException {
      return PARSER.parseFrom(input);
    }
    public static protocol.IprojHeader.Header parseFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseFrom(input, extensionRegistry);
    }
    public static protocol.IprojHeader.Header parseDelimitedFrom(java.io.InputStream input)
        throws java.io.IOException {
      return PARSER.parseDelimitedFrom(input);
    }
    public static protocol.IprojHeader.Header parseDelimitedFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseDelimitedFrom(input, extensionRegistry);
    }
    public static protocol.IprojHeader.Header parseFrom(
        com.google.protobuf.CodedInputStream input)
        throws java.io.IOException {
      return PARSER.parseFrom(input);
    }
    public static protocol.IprojHeader.Header parseFrom(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseFrom(input, extensionRegistry);
    }

    public static Builder newBuilder() { return Builder.create(); }
    public Builder newBuilderForType() { return newBuilder(); }
    public static Builder newBuilder(protocol.IprojHeader.Header prototype) {
      return newBuilder().mergeFrom(prototype);
    }
    public Builder toBuilder() { return newBuilder(this); }

    @java.lang.Override
    protected Builder newBuilderForType(
        com.google.protobuf.GeneratedMessage.BuilderParent parent) {
      Builder builder = new Builder(parent);
      return builder;
    }
    /**
     * Protobuf type {@code protocol.Header}
     */
    public static final class Builder extends
        com.google.protobuf.GeneratedMessage.Builder<Builder>
       implements protocol.IprojHeader.HeaderOrBuilder {
      public static final com.google.protobuf.Descriptors.Descriptor
          getDescriptor() {
        return protocol.IprojHeader.internal_static_protocol_Header_descriptor;
      }

      protected com.google.protobuf.GeneratedMessage.FieldAccessorTable
          internalGetFieldAccessorTable() {
        return protocol.IprojHeader.internal_static_protocol_Header_fieldAccessorTable
            .ensureFieldAccessorsInitialized(
                protocol.IprojHeader.Header.class, protocol.IprojHeader.Header.Builder.class);
      }

      // Construct using protocol.IprojHeader.Header.newBuilder()
      private Builder() {
        maybeForceBuilderInitialization();
      }

      private Builder(
          com.google.protobuf.GeneratedMessage.BuilderParent parent) {
        super(parent);
        maybeForceBuilderInitialization();
      }
      private void maybeForceBuilderInitialization() {
        if (com.google.protobuf.GeneratedMessage.alwaysUseFieldBuilders) {
        }
      }
      private static Builder create() {
        return new Builder();
      }

      public Builder clear() {
        super.clear();
        id_ = 0L;
        bitField0_ = (bitField0_ & ~0x00000001);
        msgFullName_ = "";
        bitField0_ = (bitField0_ & ~0x00000002);
        return this;
      }

      public Builder clone() {
        return create().mergeFrom(buildPartial());
      }

      public com.google.protobuf.Descriptors.Descriptor
          getDescriptorForType() {
        return protocol.IprojHeader.internal_static_protocol_Header_descriptor;
      }

      public protocol.IprojHeader.Header getDefaultInstanceForType() {
        return protocol.IprojHeader.Header.getDefaultInstance();
      }

      public protocol.IprojHeader.Header build() {
        protocol.IprojHeader.Header result = buildPartial();
        if (!result.isInitialized()) {
          throw newUninitializedMessageException(result);
        }
        return result;
      }

      public protocol.IprojHeader.Header buildPartial() {
        protocol.IprojHeader.Header result = new protocol.IprojHeader.Header(this);
        int from_bitField0_ = bitField0_;
        int to_bitField0_ = 0;
        if (((from_bitField0_ & 0x00000001) == 0x00000001)) {
          to_bitField0_ |= 0x00000001;
        }
        result.id_ = id_;
        if (((from_bitField0_ & 0x00000002) == 0x00000002)) {
          to_bitField0_ |= 0x00000002;
        }
        result.msgFullName_ = msgFullName_;
        result.bitField0_ = to_bitField0_;
        onBuilt();
        return result;
      }

      public Builder mergeFrom(com.google.protobuf.Message other) {
        if (other instanceof protocol.IprojHeader.Header) {
          return mergeFrom((protocol.IprojHeader.Header)other);
        } else {
          super.mergeFrom(other);
          return this;
        }
      }

      public Builder mergeFrom(protocol.IprojHeader.Header other) {
        if (other == protocol.IprojHeader.Header.getDefaultInstance()) return this;
        if (other.hasId()) {
          setId(other.getId());
        }
        if (other.hasMsgFullName()) {
          bitField0_ |= 0x00000002;
          msgFullName_ = other.msgFullName_;
          onChanged();
        }
        this.mergeUnknownFields(other.getUnknownFields());
        return this;
      }

      public final boolean isInitialized() {
        return true;
      }

      public Builder mergeFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws java.io.IOException {
        protocol.IprojHeader.Header parsedMessage = null;
        try {
          parsedMessage = PARSER.parsePartialFrom(input, extensionRegistry);
        } catch (com.google.protobuf.InvalidProtocolBufferException e) {
          parsedMessage = (protocol.IprojHeader.Header) e.getUnfinishedMessage();
          throw e;
        } finally {
          if (parsedMessage != null) {
            mergeFrom(parsedMessage);
          }
        }
        return this;
      }
      private int bitField0_;

      // optional uint64 id = 1;
      private long id_ ;
      /**
       * <code>optional uint64 id = 1;</code>
       */
      public boolean hasId() {
        return ((bitField0_ & 0x00000001) == 0x00000001);
      }
      /**
       * <code>optional uint64 id = 1;</code>
       */
      public long getId() {
        return id_;
      }
      /**
       * <code>optional uint64 id = 1;</code>
       */
      public Builder setId(long value) {
        bitField0_ |= 0x00000001;
        id_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>optional uint64 id = 1;</code>
       */
      public Builder clearId() {
        bitField0_ = (bitField0_ & ~0x00000001);
        id_ = 0L;
        onChanged();
        return this;
      }

      // optional string msg_full_name = 2;
      private java.lang.Object msgFullName_ = "";
      /**
       * <code>optional string msg_full_name = 2;</code>
       */
      public boolean hasMsgFullName() {
        return ((bitField0_ & 0x00000002) == 0x00000002);
      }
      /**
       * <code>optional string msg_full_name = 2;</code>
       */
      public java.lang.String getMsgFullName() {
        java.lang.Object ref = msgFullName_;
        if (!(ref instanceof java.lang.String)) {
          java.lang.String s = ((com.google.protobuf.ByteString) ref)
              .toStringUtf8();
          msgFullName_ = s;
          return s;
        } else {
          return (java.lang.String) ref;
        }
      }
      /**
       * <code>optional string msg_full_name = 2;</code>
       */
      public com.google.protobuf.ByteString
          getMsgFullNameBytes() {
        java.lang.Object ref = msgFullName_;
        if (ref instanceof String) {
          com.google.protobuf.ByteString b = 
              com.google.protobuf.ByteString.copyFromUtf8(
                  (java.lang.String) ref);
          msgFullName_ = b;
          return b;
        } else {
          return (com.google.protobuf.ByteString) ref;
        }
      }
      /**
       * <code>optional string msg_full_name = 2;</code>
       */
      public Builder setMsgFullName(
          java.lang.String value) {
        if (value == null) {
    throw new NullPointerException();
  }
  bitField0_ |= 0x00000002;
        msgFullName_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>optional string msg_full_name = 2;</code>
       */
      public Builder clearMsgFullName() {
        bitField0_ = (bitField0_ & ~0x00000002);
        msgFullName_ = getDefaultInstance().getMsgFullName();
        onChanged();
        return this;
      }
      /**
       * <code>optional string msg_full_name = 2;</code>
       */
      public Builder setMsgFullNameBytes(
          com.google.protobuf.ByteString value) {
        if (value == null) {
    throw new NullPointerException();
  }
  bitField0_ |= 0x00000002;
        msgFullName_ = value;
        onChanged();
        return this;
      }

      // @@protoc_insertion_point(builder_scope:protocol.Header)
    }

    static {
      defaultInstance = new Header(true);
      defaultInstance.initFields();
    }

    // @@protoc_insertion_point(class_scope:protocol.Header)
  }

  private static com.google.protobuf.Descriptors.Descriptor
    internal_static_protocol_Header_descriptor;
  private static
    com.google.protobuf.GeneratedMessage.FieldAccessorTable
      internal_static_protocol_Header_fieldAccessorTable;

  public static com.google.protobuf.Descriptors.FileDescriptor
      getDescriptor() {
    return descriptor;
  }
  private static com.google.protobuf.Descriptors.FileDescriptor
      descriptor;
  static {
    java.lang.String[] descriptorData = {
      "\n\014header.proto\022\010protocol\"+\n\006Header\022\n\n\002id" +
      "\030\001 \001(\004\022\025\n\rmsg_full_name\030\002 \001(\tB\rB\013IprojHe" +
      "ader"
    };
    com.google.protobuf.Descriptors.FileDescriptor.InternalDescriptorAssigner assigner =
      new com.google.protobuf.Descriptors.FileDescriptor.InternalDescriptorAssigner() {
        public com.google.protobuf.ExtensionRegistry assignDescriptors(
            com.google.protobuf.Descriptors.FileDescriptor root) {
          descriptor = root;
          internal_static_protocol_Header_descriptor =
            getDescriptor().getMessageTypes().get(0);
          internal_static_protocol_Header_fieldAccessorTable = new
            com.google.protobuf.GeneratedMessage.FieldAccessorTable(
              internal_static_protocol_Header_descriptor,
              new java.lang.String[] { "Id", "MsgFullName", });
          return null;
        }
      };
    com.google.protobuf.Descriptors.FileDescriptor
      .internalBuildGeneratedFileFrom(descriptorData,
        new com.google.protobuf.Descriptors.FileDescriptor[] {
        }, assigner);
  }

  // @@protoc_insertion_point(outer_class_scope)
}