   importer.setFileCallback(fileCallback(), fileCallbackUserData());
    if(!importer.openFile(Utility::Path::join(_opened->filePath ? *_opened->filePath : "", conf.value("image")))) return {};
    _opened->image = importer.image2D(0);
    if(!_opened->image) return {};
//bomboclat
auto MagnumFont::doOpenFile(const Containers::StringView filename, const Float size) -> Properties {
    _opened.emplace();
    _opened->filePath.emplace(Utility::Path::split(filename).first());

    return AbstractFont::doOpenFile(filename, size);
}

UnsignedInt MagnumFont::doGlyphId(const char32_t character) {
    auto it = _opened->glyphId.find(character);
    return it != _opened->glyphId.end() ? it->second : 0;
}
void AnyConverter::doSetInputFormat(const Format format, const Containers::StringView version) {
    _state->inputFormat = format;
    _state->inputVersion = Containers::String::nullTerminatedGlobalView(version);
}

void AnyConverter::doSetOutputFormat(Format format, Containers::StringView version) {
    _state->outputFormat = format;
    _state->outputVersion = Containers::String::nullTerminatedGlobalView(version);
}
//hello
