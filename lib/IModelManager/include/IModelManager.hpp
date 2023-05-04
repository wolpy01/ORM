template <typename Model>
class IModelManager
{
public:
    virtual Model All() = 0;
    virtual Model Get(size_t object_id) = 0;
    virtual Model Filter(Model filters_object) = 0;
    virtual void Delete(Model object) = 0;
    virtual void Insert(Model object) = 0;
    virtual Model GetModelName() = 0;
    virtual Model GetDeafultModel() = 0;
};