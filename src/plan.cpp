






class EdgeDetectionFilter: public IFilter {
};

class RGBCorrectionFilter: public IFilter {

};

class GammaCorrectionFilter: public IFilter {

};

class MedianFilter: public IFilter {
    
};

class FilterPipeline {
    std::vector<std::unique_ptr<IFilter>> filters;



    public:
    bool addFilter(std::unique_ptr<IFilter> filter) { 
        // TODO
    }

    bool applyFilters(Picture& pic) {// isnt const - we modify it
        // TODO
    }

    void removeFilters(){
        // TODO
    }
};

class FilterFactory {
    // TODO
    // static functions
};

class IFileManager {
public:
    virtual bool loadImage (const std::string& filename, Picture& pic) = 0;
    virtual bool saveImage (const std::string& filename, const Picture& pic) = 0;
    virtual ~IFileManager();
};

class BMPFileManager: public IFileManager {
public:
    bool loadImage (const std::string& filename, Picture& pic) override {
        // TODO
        return true;
    }
    bool saveImage (const std::string& filename, const Picture& pic) override {
        // TODO
        return true;
    }
};

