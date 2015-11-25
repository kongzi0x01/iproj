// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: line.proto

package line;

public final class Line {
  private Line() {}
  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistry registry) {
  }
  public interface LoginReqOrBuilder
      extends com.google.protobuf.MessageOrBuilder {

    // optional string user_name = 1;
    /**
     * <code>optional string user_name = 1;</code>
     */
    boolean hasUserName();
    /**
     * <code>optional string user_name = 1;</code>
     */
    java.lang.String getUserName();
    /**
     * <code>optional string user_name = 1;</code>
     */
    com.google.protobuf.ByteString
        getUserNameBytes();

    // optional string encrypted_psw = 2;
    /**
     * <code>optional string encrypted_psw = 2;</code>
     */
    boolean hasEncryptedPsw();
    /**
     * <code>optional string encrypted_psw = 2;</code>
     */
    java.lang.String getEncryptedPsw();
    /**
     * <code>optional string encrypted_psw = 2;</code>
     */
    com.google.protobuf.ByteString
        getEncryptedPswBytes();
  }
  /**
   * Protobuf type {@code line.LoginReq}
   */
  public static final class LoginReq extends
      com.google.protobuf.GeneratedMessage
      implements LoginReqOrBuilder {
    // Use LoginReq.newBuilder() to construct.
    private LoginReq(com.google.protobuf.GeneratedMessage.Builder<?> builder) {
      super(builder);
      this.unknownFields = builder.getUnknownFields();
    }
    private LoginReq(boolean noInit) { this.unknownFields = com.google.protobuf.UnknownFieldSet.getDefaultInstance(); }

    private static final LoginReq defaultInstance;
    public static LoginReq getDefaultInstance() {
      return defaultInstance;
    }

    public LoginReq getDefaultInstanceForType() {
      return defaultInstance;
    }

    private final com.google.protobuf.UnknownFieldSet unknownFields;
    @java.lang.Override
    public final com.google.protobuf.UnknownFieldSet
        getUnknownFields() {
      return this.unknownFields;
    }
    private LoginReq(
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
            case 10: {
              bitField0_ |= 0x00000001;
              userName_ = input.readBytes();
              break;
            }
            case 18: {
              bitField0_ |= 0x00000002;
              encryptedPsw_ = input.readBytes();
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
      return line.Line.internal_static_line_LoginReq_descriptor;
    }

    protected com.google.protobuf.GeneratedMessage.FieldAccessorTable
        internalGetFieldAccessorTable() {
      return line.Line.internal_static_line_LoginReq_fieldAccessorTable
          .ensureFieldAccessorsInitialized(
              line.Line.LoginReq.class, line.Line.LoginReq.Builder.class);
    }

    public static com.google.protobuf.Parser<LoginReq> PARSER =
        new com.google.protobuf.AbstractParser<LoginReq>() {
      public LoginReq parsePartialFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws com.google.protobuf.InvalidProtocolBufferException {
        return new LoginReq(input, extensionRegistry);
      }
    };

    @java.lang.Override
    public com.google.protobuf.Parser<LoginReq> getParserForType() {
      return PARSER;
    }

    private int bitField0_;
    // optional string user_name = 1;
    public static final int USER_NAME_FIELD_NUMBER = 1;
    private java.lang.Object userName_;
    /**
     * <code>optional string user_name = 1;</code>
     */
    public boolean hasUserName() {
      return ((bitField0_ & 0x00000001) == 0x00000001);
    }
    /**
     * <code>optional string user_name = 1;</code>
     */
    public java.lang.String getUserName() {
      java.lang.Object ref = userName_;
      if (ref instanceof java.lang.String) {
        return (java.lang.String) ref;
      } else {
        com.google.protobuf.ByteString bs = 
            (com.google.protobuf.ByteString) ref;
        java.lang.String s = bs.toStringUtf8();
        if (bs.isValidUtf8()) {
          userName_ = s;
        }
        return s;
      }
    }
    /**
     * <code>optional string user_name = 1;</code>
     */
    public com.google.protobuf.ByteString
        getUserNameBytes() {
      java.lang.Object ref = userName_;
      if (ref instanceof java.lang.String) {
        com.google.protobuf.ByteString b = 
            com.google.protobuf.ByteString.copyFromUtf8(
                (java.lang.String) ref);
        userName_ = b;
        return b;
      } else {
        return (com.google.protobuf.ByteString) ref;
      }
    }

    // optional string encrypted_psw = 2;
    public static final int ENCRYPTED_PSW_FIELD_NUMBER = 2;
    private java.lang.Object encryptedPsw_;
    /**
     * <code>optional string encrypted_psw = 2;</code>
     */
    public boolean hasEncryptedPsw() {
      return ((bitField0_ & 0x00000002) == 0x00000002);
    }
    /**
     * <code>optional string encrypted_psw = 2;</code>
     */
    public java.lang.String getEncryptedPsw() {
      java.lang.Object ref = encryptedPsw_;
      if (ref instanceof java.lang.String) {
        return (java.lang.String) ref;
      } else {
        com.google.protobuf.ByteString bs = 
            (com.google.protobuf.ByteString) ref;
        java.lang.String s = bs.toStringUtf8();
        if (bs.isValidUtf8()) {
          encryptedPsw_ = s;
        }
        return s;
      }
    }
    /**
     * <code>optional string encrypted_psw = 2;</code>
     */
    public com.google.protobuf.ByteString
        getEncryptedPswBytes() {
      java.lang.Object ref = encryptedPsw_;
      if (ref instanceof java.lang.String) {
        com.google.protobuf.ByteString b = 
            com.google.protobuf.ByteString.copyFromUtf8(
                (java.lang.String) ref);
        encryptedPsw_ = b;
        return b;
      } else {
        return (com.google.protobuf.ByteString) ref;
      }
    }

    private void initFields() {
      userName_ = "";
      encryptedPsw_ = "";
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
        output.writeBytes(1, getUserNameBytes());
      }
      if (((bitField0_ & 0x00000002) == 0x00000002)) {
        output.writeBytes(2, getEncryptedPswBytes());
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
          .computeBytesSize(1, getUserNameBytes());
      }
      if (((bitField0_ & 0x00000002) == 0x00000002)) {
        size += com.google.protobuf.CodedOutputStream
          .computeBytesSize(2, getEncryptedPswBytes());
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

    public static line.Line.LoginReq parseFrom(
        com.google.protobuf.ByteString data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static line.Line.LoginReq parseFrom(
        com.google.protobuf.ByteString data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static line.Line.LoginReq parseFrom(byte[] data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static line.Line.LoginReq parseFrom(
        byte[] data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static line.Line.LoginReq parseFrom(java.io.InputStream input)
        throws java.io.IOException {
      return PARSER.parseFrom(input);
    }
    public static line.Line.LoginReq parseFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseFrom(input, extensionRegistry);
    }
    public static line.Line.LoginReq parseDelimitedFrom(java.io.InputStream input)
        throws java.io.IOException {
      return PARSER.parseDelimitedFrom(input);
    }
    public static line.Line.LoginReq parseDelimitedFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseDelimitedFrom(input, extensionRegistry);
    }
    public static line.Line.LoginReq parseFrom(
        com.google.protobuf.CodedInputStream input)
        throws java.io.IOException {
      return PARSER.parseFrom(input);
    }
    public static line.Line.LoginReq parseFrom(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseFrom(input, extensionRegistry);
    }

    public static Builder newBuilder() { return Builder.create(); }
    public Builder newBuilderForType() { return newBuilder(); }
    public static Builder newBuilder(line.Line.LoginReq prototype) {
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
     * Protobuf type {@code line.LoginReq}
     */
    public static final class Builder extends
        com.google.protobuf.GeneratedMessage.Builder<Builder>
       implements line.Line.LoginReqOrBuilder {
      public static final com.google.protobuf.Descriptors.Descriptor
          getDescriptor() {
        return line.Line.internal_static_line_LoginReq_descriptor;
      }

      protected com.google.protobuf.GeneratedMessage.FieldAccessorTable
          internalGetFieldAccessorTable() {
        return line.Line.internal_static_line_LoginReq_fieldAccessorTable
            .ensureFieldAccessorsInitialized(
                line.Line.LoginReq.class, line.Line.LoginReq.Builder.class);
      }

      // Construct using line.Line.LoginReq.newBuilder()
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
        userName_ = "";
        bitField0_ = (bitField0_ & ~0x00000001);
        encryptedPsw_ = "";
        bitField0_ = (bitField0_ & ~0x00000002);
        return this;
      }

      public Builder clone() {
        return create().mergeFrom(buildPartial());
      }

      public com.google.protobuf.Descriptors.Descriptor
          getDescriptorForType() {
        return line.Line.internal_static_line_LoginReq_descriptor;
      }

      public line.Line.LoginReq getDefaultInstanceForType() {
        return line.Line.LoginReq.getDefaultInstance();
      }

      public line.Line.LoginReq build() {
        line.Line.LoginReq result = buildPartial();
        if (!result.isInitialized()) {
          throw newUninitializedMessageException(result);
        }
        return result;
      }

      public line.Line.LoginReq buildPartial() {
        line.Line.LoginReq result = new line.Line.LoginReq(this);
        int from_bitField0_ = bitField0_;
        int to_bitField0_ = 0;
        if (((from_bitField0_ & 0x00000001) == 0x00000001)) {
          to_bitField0_ |= 0x00000001;
        }
        result.userName_ = userName_;
        if (((from_bitField0_ & 0x00000002) == 0x00000002)) {
          to_bitField0_ |= 0x00000002;
        }
        result.encryptedPsw_ = encryptedPsw_;
        result.bitField0_ = to_bitField0_;
        onBuilt();
        return result;
      }

      public Builder mergeFrom(com.google.protobuf.Message other) {
        if (other instanceof line.Line.LoginReq) {
          return mergeFrom((line.Line.LoginReq)other);
        } else {
          super.mergeFrom(other);
          return this;
        }
      }

      public Builder mergeFrom(line.Line.LoginReq other) {
        if (other == line.Line.LoginReq.getDefaultInstance()) return this;
        if (other.hasUserName()) {
          bitField0_ |= 0x00000001;
          userName_ = other.userName_;
          onChanged();
        }
        if (other.hasEncryptedPsw()) {
          bitField0_ |= 0x00000002;
          encryptedPsw_ = other.encryptedPsw_;
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
        line.Line.LoginReq parsedMessage = null;
        try {
          parsedMessage = PARSER.parsePartialFrom(input, extensionRegistry);
        } catch (com.google.protobuf.InvalidProtocolBufferException e) {
          parsedMessage = (line.Line.LoginReq) e.getUnfinishedMessage();
          throw e;
        } finally {
          if (parsedMessage != null) {
            mergeFrom(parsedMessage);
          }
        }
        return this;
      }
      private int bitField0_;

      // optional string user_name = 1;
      private java.lang.Object userName_ = "";
      /**
       * <code>optional string user_name = 1;</code>
       */
      public boolean hasUserName() {
        return ((bitField0_ & 0x00000001) == 0x00000001);
      }
      /**
       * <code>optional string user_name = 1;</code>
       */
      public java.lang.String getUserName() {
        java.lang.Object ref = userName_;
        if (!(ref instanceof java.lang.String)) {
          java.lang.String s = ((com.google.protobuf.ByteString) ref)
              .toStringUtf8();
          userName_ = s;
          return s;
        } else {
          return (java.lang.String) ref;
        }
      }
      /**
       * <code>optional string user_name = 1;</code>
       */
      public com.google.protobuf.ByteString
          getUserNameBytes() {
        java.lang.Object ref = userName_;
        if (ref instanceof String) {
          com.google.protobuf.ByteString b = 
              com.google.protobuf.ByteString.copyFromUtf8(
                  (java.lang.String) ref);
          userName_ = b;
          return b;
        } else {
          return (com.google.protobuf.ByteString) ref;
        }
      }
      /**
       * <code>optional string user_name = 1;</code>
       */
      public Builder setUserName(
          java.lang.String value) {
        if (value == null) {
    throw new NullPointerException();
  }
  bitField0_ |= 0x00000001;
        userName_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>optional string user_name = 1;</code>
       */
      public Builder clearUserName() {
        bitField0_ = (bitField0_ & ~0x00000001);
        userName_ = getDefaultInstance().getUserName();
        onChanged();
        return this;
      }
      /**
       * <code>optional string user_name = 1;</code>
       */
      public Builder setUserNameBytes(
          com.google.protobuf.ByteString value) {
        if (value == null) {
    throw new NullPointerException();
  }
  bitField0_ |= 0x00000001;
        userName_ = value;
        onChanged();
        return this;
      }

      // optional string encrypted_psw = 2;
      private java.lang.Object encryptedPsw_ = "";
      /**
       * <code>optional string encrypted_psw = 2;</code>
       */
      public boolean hasEncryptedPsw() {
        return ((bitField0_ & 0x00000002) == 0x00000002);
      }
      /**
       * <code>optional string encrypted_psw = 2;</code>
       */
      public java.lang.String getEncryptedPsw() {
        java.lang.Object ref = encryptedPsw_;
        if (!(ref instanceof java.lang.String)) {
          java.lang.String s = ((com.google.protobuf.ByteString) ref)
              .toStringUtf8();
          encryptedPsw_ = s;
          return s;
        } else {
          return (java.lang.String) ref;
        }
      }
      /**
       * <code>optional string encrypted_psw = 2;</code>
       */
      public com.google.protobuf.ByteString
          getEncryptedPswBytes() {
        java.lang.Object ref = encryptedPsw_;
        if (ref instanceof String) {
          com.google.protobuf.ByteString b = 
              com.google.protobuf.ByteString.copyFromUtf8(
                  (java.lang.String) ref);
          encryptedPsw_ = b;
          return b;
        } else {
          return (com.google.protobuf.ByteString) ref;
        }
      }
      /**
       * <code>optional string encrypted_psw = 2;</code>
       */
      public Builder setEncryptedPsw(
          java.lang.String value) {
        if (value == null) {
    throw new NullPointerException();
  }
  bitField0_ |= 0x00000002;
        encryptedPsw_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>optional string encrypted_psw = 2;</code>
       */
      public Builder clearEncryptedPsw() {
        bitField0_ = (bitField0_ & ~0x00000002);
        encryptedPsw_ = getDefaultInstance().getEncryptedPsw();
        onChanged();
        return this;
      }
      /**
       * <code>optional string encrypted_psw = 2;</code>
       */
      public Builder setEncryptedPswBytes(
          com.google.protobuf.ByteString value) {
        if (value == null) {
    throw new NullPointerException();
  }
  bitField0_ |= 0x00000002;
        encryptedPsw_ = value;
        onChanged();
        return this;
      }

      // @@protoc_insertion_point(builder_scope:line.LoginReq)
    }

    static {
      defaultInstance = new LoginReq(true);
      defaultInstance.initFields();
    }

    // @@protoc_insertion_point(class_scope:line.LoginReq)
  }

  public interface LoginRspOrBuilder
      extends com.google.protobuf.MessageOrBuilder {

    // optional uint32 result = 1;
    /**
     * <code>optional uint32 result = 1;</code>
     *
     * <pre>
     *正常则为0
     * </pre>
     */
    boolean hasResult();
    /**
     * <code>optional uint32 result = 1;</code>
     *
     * <pre>
     *正常则为0
     * </pre>
     */
    int getResult();
  }
  /**
   * Protobuf type {@code line.LoginRsp}
   */
  public static final class LoginRsp extends
      com.google.protobuf.GeneratedMessage
      implements LoginRspOrBuilder {
    // Use LoginRsp.newBuilder() to construct.
    private LoginRsp(com.google.protobuf.GeneratedMessage.Builder<?> builder) {
      super(builder);
      this.unknownFields = builder.getUnknownFields();
    }
    private LoginRsp(boolean noInit) { this.unknownFields = com.google.protobuf.UnknownFieldSet.getDefaultInstance(); }

    private static final LoginRsp defaultInstance;
    public static LoginRsp getDefaultInstance() {
      return defaultInstance;
    }

    public LoginRsp getDefaultInstanceForType() {
      return defaultInstance;
    }

    private final com.google.protobuf.UnknownFieldSet unknownFields;
    @java.lang.Override
    public final com.google.protobuf.UnknownFieldSet
        getUnknownFields() {
      return this.unknownFields;
    }
    private LoginRsp(
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
              result_ = input.readUInt32();
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
      return line.Line.internal_static_line_LoginRsp_descriptor;
    }

    protected com.google.protobuf.GeneratedMessage.FieldAccessorTable
        internalGetFieldAccessorTable() {
      return line.Line.internal_static_line_LoginRsp_fieldAccessorTable
          .ensureFieldAccessorsInitialized(
              line.Line.LoginRsp.class, line.Line.LoginRsp.Builder.class);
    }

    public static com.google.protobuf.Parser<LoginRsp> PARSER =
        new com.google.protobuf.AbstractParser<LoginRsp>() {
      public LoginRsp parsePartialFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws com.google.protobuf.InvalidProtocolBufferException {
        return new LoginRsp(input, extensionRegistry);
      }
    };

    @java.lang.Override
    public com.google.protobuf.Parser<LoginRsp> getParserForType() {
      return PARSER;
    }

    private int bitField0_;
    // optional uint32 result = 1;
    public static final int RESULT_FIELD_NUMBER = 1;
    private int result_;
    /**
     * <code>optional uint32 result = 1;</code>
     *
     * <pre>
     *正常则为0
     * </pre>
     */
    public boolean hasResult() {
      return ((bitField0_ & 0x00000001) == 0x00000001);
    }
    /**
     * <code>optional uint32 result = 1;</code>
     *
     * <pre>
     *正常则为0
     * </pre>
     */
    public int getResult() {
      return result_;
    }

    private void initFields() {
      result_ = 0;
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
        output.writeUInt32(1, result_);
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
          .computeUInt32Size(1, result_);
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

    public static line.Line.LoginRsp parseFrom(
        com.google.protobuf.ByteString data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static line.Line.LoginRsp parseFrom(
        com.google.protobuf.ByteString data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static line.Line.LoginRsp parseFrom(byte[] data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static line.Line.LoginRsp parseFrom(
        byte[] data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static line.Line.LoginRsp parseFrom(java.io.InputStream input)
        throws java.io.IOException {
      return PARSER.parseFrom(input);
    }
    public static line.Line.LoginRsp parseFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseFrom(input, extensionRegistry);
    }
    public static line.Line.LoginRsp parseDelimitedFrom(java.io.InputStream input)
        throws java.io.IOException {
      return PARSER.parseDelimitedFrom(input);
    }
    public static line.Line.LoginRsp parseDelimitedFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseDelimitedFrom(input, extensionRegistry);
    }
    public static line.Line.LoginRsp parseFrom(
        com.google.protobuf.CodedInputStream input)
        throws java.io.IOException {
      return PARSER.parseFrom(input);
    }
    public static line.Line.LoginRsp parseFrom(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseFrom(input, extensionRegistry);
    }

    public static Builder newBuilder() { return Builder.create(); }
    public Builder newBuilderForType() { return newBuilder(); }
    public static Builder newBuilder(line.Line.LoginRsp prototype) {
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
     * Protobuf type {@code line.LoginRsp}
     */
    public static final class Builder extends
        com.google.protobuf.GeneratedMessage.Builder<Builder>
       implements line.Line.LoginRspOrBuilder {
      public static final com.google.protobuf.Descriptors.Descriptor
          getDescriptor() {
        return line.Line.internal_static_line_LoginRsp_descriptor;
      }

      protected com.google.protobuf.GeneratedMessage.FieldAccessorTable
          internalGetFieldAccessorTable() {
        return line.Line.internal_static_line_LoginRsp_fieldAccessorTable
            .ensureFieldAccessorsInitialized(
                line.Line.LoginRsp.class, line.Line.LoginRsp.Builder.class);
      }

      // Construct using line.Line.LoginRsp.newBuilder()
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
        result_ = 0;
        bitField0_ = (bitField0_ & ~0x00000001);
        return this;
      }

      public Builder clone() {
        return create().mergeFrom(buildPartial());
      }

      public com.google.protobuf.Descriptors.Descriptor
          getDescriptorForType() {
        return line.Line.internal_static_line_LoginRsp_descriptor;
      }

      public line.Line.LoginRsp getDefaultInstanceForType() {
        return line.Line.LoginRsp.getDefaultInstance();
      }

      public line.Line.LoginRsp build() {
        line.Line.LoginRsp result = buildPartial();
        if (!result.isInitialized()) {
          throw newUninitializedMessageException(result);
        }
        return result;
      }

      public line.Line.LoginRsp buildPartial() {
        line.Line.LoginRsp result = new line.Line.LoginRsp(this);
        int from_bitField0_ = bitField0_;
        int to_bitField0_ = 0;
        if (((from_bitField0_ & 0x00000001) == 0x00000001)) {
          to_bitField0_ |= 0x00000001;
        }
        result.result_ = result_;
        result.bitField0_ = to_bitField0_;
        onBuilt();
        return result;
      }

      public Builder mergeFrom(com.google.protobuf.Message other) {
        if (other instanceof line.Line.LoginRsp) {
          return mergeFrom((line.Line.LoginRsp)other);
        } else {
          super.mergeFrom(other);
          return this;
        }
      }

      public Builder mergeFrom(line.Line.LoginRsp other) {
        if (other == line.Line.LoginRsp.getDefaultInstance()) return this;
        if (other.hasResult()) {
          setResult(other.getResult());
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
        line.Line.LoginRsp parsedMessage = null;
        try {
          parsedMessage = PARSER.parsePartialFrom(input, extensionRegistry);
        } catch (com.google.protobuf.InvalidProtocolBufferException e) {
          parsedMessage = (line.Line.LoginRsp) e.getUnfinishedMessage();
          throw e;
        } finally {
          if (parsedMessage != null) {
            mergeFrom(parsedMessage);
          }
        }
        return this;
      }
      private int bitField0_;

      // optional uint32 result = 1;
      private int result_ ;
      /**
       * <code>optional uint32 result = 1;</code>
       *
       * <pre>
       *正常则为0
       * </pre>
       */
      public boolean hasResult() {
        return ((bitField0_ & 0x00000001) == 0x00000001);
      }
      /**
       * <code>optional uint32 result = 1;</code>
       *
       * <pre>
       *正常则为0
       * </pre>
       */
      public int getResult() {
        return result_;
      }
      /**
       * <code>optional uint32 result = 1;</code>
       *
       * <pre>
       *正常则为0
       * </pre>
       */
      public Builder setResult(int value) {
        bitField0_ |= 0x00000001;
        result_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>optional uint32 result = 1;</code>
       *
       * <pre>
       *正常则为0
       * </pre>
       */
      public Builder clearResult() {
        bitField0_ = (bitField0_ & ~0x00000001);
        result_ = 0;
        onChanged();
        return this;
      }

      // @@protoc_insertion_point(builder_scope:line.LoginRsp)
    }

    static {
      defaultInstance = new LoginRsp(true);
      defaultInstance.initFields();
    }

    // @@protoc_insertion_point(class_scope:line.LoginRsp)
  }

  private static com.google.protobuf.Descriptors.Descriptor
    internal_static_line_LoginReq_descriptor;
  private static
    com.google.protobuf.GeneratedMessage.FieldAccessorTable
      internal_static_line_LoginReq_fieldAccessorTable;
  private static com.google.protobuf.Descriptors.Descriptor
    internal_static_line_LoginRsp_descriptor;
  private static
    com.google.protobuf.GeneratedMessage.FieldAccessorTable
      internal_static_line_LoginRsp_fieldAccessorTable;

  public static com.google.protobuf.Descriptors.FileDescriptor
      getDescriptor() {
    return descriptor;
  }
  private static com.google.protobuf.Descriptors.FileDescriptor
      descriptor;
  static {
    java.lang.String[] descriptorData = {
      "\n\nline.proto\022\004line\"4\n\010LoginReq\022\021\n\tuser_n" +
      "ame\030\001 \001(\t\022\025\n\rencrypted_psw\030\002 \001(\t\"\032\n\010Logi" +
      "nRsp\022\016\n\006result\030\001 \001(\r"
    };
    com.google.protobuf.Descriptors.FileDescriptor.InternalDescriptorAssigner assigner =
      new com.google.protobuf.Descriptors.FileDescriptor.InternalDescriptorAssigner() {
        public com.google.protobuf.ExtensionRegistry assignDescriptors(
            com.google.protobuf.Descriptors.FileDescriptor root) {
          descriptor = root;
          internal_static_line_LoginReq_descriptor =
            getDescriptor().getMessageTypes().get(0);
          internal_static_line_LoginReq_fieldAccessorTable = new
            com.google.protobuf.GeneratedMessage.FieldAccessorTable(
              internal_static_line_LoginReq_descriptor,
              new java.lang.String[] { "UserName", "EncryptedPsw", });
          internal_static_line_LoginRsp_descriptor =
            getDescriptor().getMessageTypes().get(1);
          internal_static_line_LoginRsp_fieldAccessorTable = new
            com.google.protobuf.GeneratedMessage.FieldAccessorTable(
              internal_static_line_LoginRsp_descriptor,
              new java.lang.String[] { "Result", });
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