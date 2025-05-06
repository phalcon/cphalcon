
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

use Phalcon\Db\Adapter\AdapterInterface;
use Phalcon\Di\DiInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface as EventsManagerInterface;
use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Mvc\Model\Query\BuilderInterface;
use Phalcon\Mvc\Model\Query\StatusInterface;
use Phalcon\Storage\Adapter\AbstractAdapter;
use ReflectionClass;
use ReflectionProperty;

/**
 * Phalcon\Mvc\Model\Manager
 *
 * This components controls the initialization of models, keeping record of
 * relations between the different models of the application.
 *
 * A ModelsManager is injected to a model via a Dependency Injector/Services
 * Container such as Phalcon\Di\Di.
 *
 * ```php
 * use Phalcon\Di\Di;
 * use Phalcon\Mvc\Model\Manager as ModelsManager;
 *
 * $di = new Di();
 *
 * $di->set(
 *     "modelsManager",
 *     function() {
 *         return new ModelsManager();
 *     }
 * );
 *
 * $robot = new Robots($di);
 * ```
 */
class Manager implements ManagerInterface, InjectionAwareInterface, EventsAwareInterface
{
    /**
     * @var array
     */
    protected aliases = [];

    /**
     * Models' behaviors
     *
     * @var array
     */
    protected behaviors = [];

    /**
     * Belongs to relations
     *
     * @var array
     */
    protected belongsTo = [];

    /**
     * All the relationships by model
     *
     * @var array
     */
    protected belongsToSingle = [];

    /**
     * @var BuilderInterface|null
     */
    protected builder = null;

    /**
     * @var DiInterface|null
     */
    protected container = null;

    /**
     * @var array
     */
    protected customEventsManager = [];

    /**
     * Does the model use dynamic update, instead of updating all rows?
     *
     * @var array
     */
    protected dynamicUpdate = [];

    /**
     * @var EventsManagerInterface|null
     */
    protected eventsManager = null;

    /**
     * Has many relations
     *
     * @var array
     */
    protected hasMany = [];

    /**
     * Has many relations by model
     *
     * @var array
     */
    protected hasManySingle = [];

    /**
     * Has many-Through relations
     *
     * @var array
     */
    protected hasManyToMany = [];

    /**
     * Has many-Through relations by model
     *
     * @var array
     */
    protected hasManyToManySingle = [];

    /**
     * Has one relations
     *
     * @var array
     */
    protected hasOne = [];

    /**
     * Has one relations by model
     *
     * @var array
     */
    protected hasOneSingle = [];

    /**
     * Has one through relations
     *
     * @var array
     */
    protected hasOneThrough = [];

    /**
     * Has one through relations by model
     *
     * @var array
     */
    protected hasOneThroughSingle = [];

    /**
     * Mark initialized models
     *
     * @var array
     */
    protected initialized = [];

    /**
     * @var array
     */
    protected keepSnapshots = [];

    /**
     * Last model initialized
     *
     * @var ModelInterface|null
     */
    protected lastInitialized = null;

    /**
     * Last query created/executed
     *
     * @var QueryInterface|null
     */
    protected lastQuery = null;

    /**
     * @var array
     */
    protected modelVisibility = [];

    /**
     * @var string
     */
    protected prefix = "";

    /**
     * @var array
     */
    protected readConnectionServices = [];

    /**
     * @var array
     */
    protected sources = [];

    /**
     * @var array
     */
    protected schemas = [];

    /**
     * @var array
     */
    protected writeConnectionServices = [];

    /**
     * Stores a list of reusable instances
     *
     * @var array
     */
    protected reusable = [];

    /**
     * Thread cache.
     *
     * @var AbstractAdapter|null
     */
    protected sessionCache = null;

    /**
     * Destroys the current PHQL cache
     */
    public function __destruct()
    {
        phalcon_orm_destroy_cache();

        Query::clean();
    }

    /**
     * Binds a behavior to a model
     *
     * @param ModelInterface    $model
     * @param BehaviorInterface $behavior
     */
    public function addBehavior(
        <ModelInterface> model,
        <BehaviorInterface> behavior
    ) -> void {
        var entityName;

        let entityName = get_class_lower(model);

        if !isset this->behaviors[entityName] {
            let this->behaviors[entityName] = [];
        }

        /**
         * Append the behavior to the list of behaviors
         */
        let this->behaviors[entityName][] = behavior;
    }

    /**
     * Setup a relation reverse many to one between two models
     *
     * @param ModelInterface $model
     * @param mixed          $fields
     * @param string         $referencedModel
     * @param mixed          $referencedFields
     * @param array          $options
     *
     * @return RelationInterface
     */
    public function addBelongsTo(
        <ModelInterface> model,
        var fields,
        string! referencedModel,
        var referencedFields,
        array options = []
    ) -> <RelationInterface> {
        var entityName, referencedEntity, relation, relations, alias,
            lowerAlias, singleRelations;
        string keyRelation;

        let entityName = get_class_lower(model),
            referencedEntity = strtolower(referencedModel);

        let keyRelation = entityName . "$" . referencedEntity;

        if !fetch relations, this->belongsTo[keyRelation] {
            let relations = [];
        }

        /**
         * Check if the number of fields are the same
         */
        if typeof referencedFields == "array" {
            if unlikely count(fields) != count(referencedFields) {
                throw new Exception(
                    "Number of referenced fields are not the same"
                );
            }
        }

        /**
         * Create a relationship instance
         */
        let relation = new Relation(
            Relation::BELONGS_TO,
            referencedModel,
            fields,
            referencedFields,
            options
        );

        /**
         * Check an alias for the relation
         */
        if fetch alias, options["alias"] {
            if unlikely typeof alias != "string" {
                throw new Exception("Relation alias must be a string");
            }

            let lowerAlias = strtolower(alias);
        } else {
            let lowerAlias = referencedEntity;
        }

        /**
         * Append a new relationship
         * Update the global alias
         * Update the relations
         */
        let relations[] = relation,
            this->aliases[entityName . "$" . lowerAlias] = relation,
            this->belongsTo[keyRelation] = relations;

        /**
         * Get existing relations by model
         */
        if !fetch singleRelations, this->belongsToSingle[entityName] {
            let singleRelations = [];
        }

        /**
         * Append a new relationship
         */
        let singleRelations[] = relation;

        /**
         * Update relations by model
         */
        let this->belongsToSingle[entityName] = singleRelations;

        return relation;
    }

    /**
     * Setup a relation 1-n between two models
     *
     * @param ModelInterface $model
     * @param mixed          $fields
     * @param string         $referencedModel
     * @param mixed          $referencedFields
     * @param array          $options
     *
     * @return RelationInterface
     */
    public function addHasMany(
        <ModelInterface> model,
        var fields,
        string! referencedModel,
        var referencedFields,
        array options = []
    ) -> <RelationInterface> {
        var entityName, referencedEntity, hasMany, relation, relations, alias,
            lowerAlias, singleRelations;
        string keyRelation;

        let entityName = get_class_lower(model),
            referencedEntity = strtolower(referencedModel),
            keyRelation = entityName . "$" . referencedEntity;

        let hasMany = this->hasMany;

        if !fetch relations, hasMany[keyRelation] {
            let relations = [];
        }

        /**
         * Check if the number of fields are the same
         */
        if typeof referencedFields == "array" {
            if unlikely count(fields) != count(referencedFields) {
                throw new Exception(
                    "Number of referenced fields are not the same"
                );
            }
        }

        /**
         * Create a relationship instance
         */
        let relation = new Relation(
            Relation::HAS_MANY,
            referencedModel,
            fields,
            referencedFields,
            options
        );

        /**
         * Check an alias for the relation
         */
        if fetch alias, options["alias"] {
            if unlikely typeof alias != "string" {
                throw new Exception("Relation alias must be a string");
            }

            let lowerAlias = strtolower(alias);
        } else {
            let lowerAlias = referencedEntity;
        }

        /**
         * Append a new relationship
         * Update the global alias
         * Update the relations
         */
        let relations[] = relation,
            this->aliases[entityName . "$" . lowerAlias] = relation,
            this->hasMany[keyRelation] = relations;

        /**
         * Get existing relations by model
         */
        if !fetch singleRelations, this->hasManySingle[entityName] {
            let singleRelations = [];
        }

        /**
         * Append a new relationship
         */
        let singleRelations[] = relation;

        /**
         * Update relations by model
         */
        let this->hasManySingle[entityName] = singleRelations;

        return relation;
    }

    /**
     * Setups a relation n-m between two models
     *
     * @param ModelInterface $model
     * @param mixed          $fields
     * @param string         $intermediateModel
     * @param mixed          $intermediateFields
     * @param mixed          $intermediateReferencedFields
     * @param string         $referencedModel
     * @param mixed          $referencedFields
     * @param array          $options
     *
     * @return RelationInterface
     */
    public function addHasManyToMany(
        <ModelInterface> model,
        var fields,
        string! intermediateModel,
        var intermediateFields,
        var intermediateReferencedFields,
        string! referencedModel,
        var referencedFields,
        array options = []
    ) -> <RelationInterface> {
        var entityName, referencedEntity, hasManyToMany, relation, relations,
            alias, lowerAlias, singleRelations, intermediateEntity;
        string keyRelation;

        let entityName = get_class_lower(model),
            intermediateEntity = strtolower(intermediateModel),
            referencedEntity = strtolower(referencedModel),
            keyRelation = entityName . "$" . referencedEntity;

        let hasManyToMany = this->hasManyToMany;

        if !fetch relations, hasManyToMany[keyRelation] {
            let relations = [];
        }

        /**
         * Check if the number of fields are the same from the model to the
         * intermediate model
         */
        if typeof intermediateFields == "array" {
            if unlikely count(fields) != count(intermediateFields) {
                throw new Exception(
                    "Number of referenced fields are not the same"
                );
            }
        }

        /**
         * Check if the number of fields are the same from the intermediate
         * model to the referenced model
         */
        if typeof intermediateReferencedFields == "array" {
            if unlikely count(fields) != count(intermediateFields) {
                throw new Exception(
                    "Number of referenced fields are not the same"
                );
            }
        }

        /**
         * Create a relationship instance
         */
        let relation = new Relation(
            Relation::HAS_MANY_THROUGH,
            referencedModel,
            fields,
            referencedFields,
            options
        );

        /**
         * Set extended intermediate relation data
         */
        relation->setIntermediateRelation(
            intermediateFields,
            intermediateModel,
            intermediateReferencedFields
        );

        /**
         * Check an alias for the relation
         */
        if fetch alias, options["alias"] {
            if typeof alias != "string" {
                throw new Exception("Relation alias must be a string");
            }

            let lowerAlias = strtolower(alias);
        } else {
            let lowerAlias = referencedEntity;
        }

        /**
         * Append a new relationship
         */
        let relations[] = relation;

        /**
         * Update the global alias
         */
        let this->aliases[entityName . "$" . lowerAlias] = relation;

        /**
         * Update the relations
         */
        let this->hasManyToMany[keyRelation] = relations;

        /**
         * Get existing relations by model
         */
        if !fetch singleRelations, this->hasManyToManySingle[entityName] {
            let singleRelations = [];
        }

        /**
         * Append a new relationship
         */
        let singleRelations[] = relation;

        /**
         * Update relations by model
         */
        let this->hasManyToManySingle[entityName] = singleRelations;

        return relation;
    }

    /**
     * Setup a 1-1 relation between two models
     *
     * @param ModelInterface $model
     * @param mixed          $fields
     * @param string         $referencedModel
     * @param mixed          $referencedFields
     * @param array          $options
     *
     * @return RelationInterface
     */
    public function addHasOne(
        <ModelInterface> model,
        var fields,
        string! referencedModel,
        var referencedFields,
        array options = []
    ) -> <RelationInterface> {
        var entityName, referencedEntity, relation, relations, alias,
            lowerAlias, singleRelations;
        string keyRelation;

        let entityName = get_class_lower(model),
            referencedEntity = strtolower(referencedModel);

        let keyRelation = entityName . "$" . referencedEntity;

        if !fetch relations, this->hasOne[keyRelation] {
            let relations = [];
        }

        /**
         * Check if the number of fields are the same
         */
        if typeof referencedFields == "array" {
            if unlikely count(fields) != count(referencedFields) {
                throw new Exception(
                    "Number of referenced fields are not the same"
                );
            }
        }

        /**
         * Create a relationship instance
         */
        let relation = new Relation(
            Relation::HAS_ONE,
            referencedModel,
            fields,
            referencedFields,
            options
        );

        /**
         * Check an alias for the relation
         */
        if fetch alias, options["alias"] {
            if unlikely typeof alias != "string" {
                throw new Exception("Relation alias must be a string");
            }

            let lowerAlias = strtolower(alias);
        } else {
            let lowerAlias = referencedEntity;
        }

        /**
         * Append a new relationship
         * Update the global alias
         * Update the relations
         */
        let relations[] = relation,
            this->aliases[entityName . "$" . lowerAlias] = relation,
            this->hasOne[keyRelation] = relations;

        /**
         * Get existing relations by model
         */
        if !fetch singleRelations, this->hasOneSingle[entityName] {
            let singleRelations = [];
        }

        /**
         * Append a new relationship
         */
        let singleRelations[] = relation;

        /**
         * Update relations by model
         */
        let this->hasOneSingle[entityName] = singleRelations;

        return relation;
    }

    /**
     * Setups a relation 1-1 between two models using an intermediate model
     *
     * @param ModelInterface $model
     * @param mixed          $fields
     * @param string         $intermediateModel
     * @param mixed          $intermediateFields
     * @param mixed          $intermediateReferencedFields
     * @param string         $referencedModel
     * @param mixed          $referencedFields
     * @param array          $options
     *
     * @return RelationInterface
     */
    public function addHasOneThrough(
        <ModelInterface> model,
        var fields,
        string! intermediateModel,
        var intermediateFields,
        var intermediateReferencedFields,
        string! referencedModel,
        var referencedFields,
        array options = []
    ) -> <RelationInterface> {
        var entityName, referencedEntity, hasOneThrough, relation, relations,
            alias, lowerAlias, singleRelations, intermediateEntity;
        string keyRelation;

        let entityName = get_class_lower(model),
            intermediateEntity = strtolower(intermediateModel),
            referencedEntity = strtolower(referencedModel),
            keyRelation = entityName . "$" . referencedEntity;

        let hasOneThrough = this->hasOneThrough;

        if !fetch relations, hasOneThrough[keyRelation] {
            let relations = [];
        }

        /**
         * Check if the number of fields are the same from the model to the
         * intermediate model
         */
        if typeof intermediateFields == "array" {
            if unlikely count(fields) != count(intermediateFields) {
                throw new Exception(
                    "Number of referenced fields are not the same"
                );
            }
        }

        /**
         * Check if the number of fields are the same from the intermediate
         * model to the referenced model
         */
        if typeof intermediateReferencedFields == "array" {
            if unlikely count(fields) != count(intermediateFields) {
                throw new Exception(
                    "Number of referenced fields are not the same"
                );
            }
        }

        /**
         * Create a relationship instance
         */
        let relation = new Relation(
            Relation::HAS_ONE_THROUGH,
            referencedModel,
            fields,
            referencedFields,
            options
        );

        /**
         * Set extended intermediate relation data
         */
        relation->setIntermediateRelation(
            intermediateFields,
            intermediateModel,
            intermediateReferencedFields
        );

        /**
         * Check an alias for the relation
         */
        if fetch alias, options["alias"] {
            if typeof alias != "string" {
                throw new Exception("Relation alias must be a string");
            }

            let lowerAlias = strtolower(alias);
        } else {
            let lowerAlias = referencedEntity;
        }

        /**
         * Append a new relationship
         */
        let relations[] = relation;

        /**
         * Update the global alias
         */
        let this->aliases[entityName . "$" . lowerAlias] = relation;

        /**
         * Update the relations
         */
        let this->hasOneThrough[keyRelation] = relations;

        /**
         * Get existing relations by model
         */
        if !fetch singleRelations, this->hasOneThroughSingle[entityName] {
            let singleRelations = [];
        }

        /**
         * Append a new relationship
         */
        let singleRelations[] = relation;

        /**
         * Update relations by model
         */
        let this->hasOneThroughSingle[entityName] = singleRelations;

        return relation;
    }

    /**
     * Clears the internal reusable list
     */
    public function clearReusableObjects() -> void
    {
        let this->reusable = [];
    }

    /**
     * Creates a Phalcon\Mvc\Model\Query\Builder
     *
     * @param array|string|null params
     */
    public function createBuilder(var params = null) -> <BuilderInterface>
    {
        var container;

        let container = <DiInterface> this->container;

        if unlikely typeof container != "object" {
            throw new Exception(
                "A dependency injection container is required to access the services related to the ORM"
            );
        }

        /**
         * Gets Builder instance from DI container
         */
        let this->builder = <BuilderInterface> container->get(
            "Phalcon\\Mvc\\Model\\Query\\Builder",
            [
                params,
                container
            ]
        );

        return this->builder;
    }

    /**
     * Creates a Phalcon\Mvc\Model\Query without execute it
     *
     * @param string $phql
     *
     * @return QueryInterface
     */
    public function createQuery(string! phql) -> <QueryInterface>
    {
        var container, query;

        let container = this->container;

        if unlikely typeof container != "object" {
            throw new Exception(
                "A dependency injection container is required to access the services related to the ORM"
            );
        }

        /**
         * Create a query
         */
        let query = <QueryInterface> container->get(
            "Phalcon\\Mvc\\Model\\Query",
            [phql, container]
        );

        let this->lastQuery = query;

        return query;
    }

    /**
     * Creates a Phalcon\Mvc\Model\Query and execute it
     *
     * ```php
     * $model = new Robots();
     * $manager = $model->getModelsManager();
     *
     * // \Phalcon\Mvc\Model\Resultset\Simple
     * $manager->executeQuery('SELECT * FROM Robots');
     *
     * // \Phalcon\Mvc\Model\Resultset\Complex
     * $manager->executeQuery('SELECT COUNT(type) FROM Robots GROUP BY type');
     *
     * // \Phalcon\Mvc\Model\Query\StatusInterface
     * $manager->executeQuery('INSERT INTO Robots (id) VALUES (1)');
     *
     * // \Phalcon\Mvc\Model\Query\StatusInterface
     * $manager->executeQuery('UPDATE Robots SET id = 0 WHERE id = :id:', ['id' => 1]);
     *
     * // \Phalcon\Mvc\Model\Query\StatusInterface
     * $manager->executeQuery('DELETE FROM Robots WHERE id = :id:', ['id' => 1]);
     * ```
     *
     * @param string     $phql
     * @param array|null $placeholders
     * @param array|null $types
     *
     * @return ResultsetInterface|StatusInterface
     */
    public function executeQuery(string! phql, var placeholders = null, var types = null) -> var
    {
        var query;

        let query = this->createQuery(phql);

        if typeof placeholders == "array" {
            query->setBindParams(placeholders);
        }

        if typeof types == "array" {
            query->setBindTypes(types);
        }

        /**
         * Execute the query
         */
        return query->execute();
    }

    /**
     * Checks whether a model has a belongsTo relation with another model
     * @deprecated
     */
    public function existsBelongsTo(string! modelName, string! modelRelation) -> bool
    {
        return this->hasBelongsTo(modelName, modelRelation);
    }

    /**
     * Checks whether a model has a hasMany relation with another model
     * @deprecated
     */
    public function existsHasMany(string! modelName, string! modelRelation) -> bool
    {
        return this->hasHasMany(modelName, modelRelation);
    }

    /**
     * Checks whether a model has a hasManyToMany relation with another model
     * @deprecated
     */
    public function existsHasManyToMany(string! modelName, string! modelRelation) -> bool
    {
        return this->hasHasManyToMany(modelName, modelRelation);
    }

    /**
     * Checks whether a model has a hasOne relation with another model
     * @deprecated
     */
    public function existsHasOne(string! modelName, string! modelRelation) -> bool
    {
        return this->hasHasOne(modelName, modelRelation);
    }

    /**
     * Checks whether a model has a hasOneThrough relation with another model
     * @deprecated
     */
    public function existsHasOneThrough(string! modelName, string! modelRelation) -> bool
    {
        return this->hasHasOneThrough(modelName, modelRelation);
    }

    /**
     * Gets all the belongsTo relations defined in a model
     *
     *```php
     * $relations = $modelsManager->getBelongsTo(
     *     new Robots()
     * );
     *```
     *
     * @param ModelInterface $model
     *
     * @return RelationInterface[] | array
     */
    public function getBelongsTo(<ModelInterface> model) -> <RelationInterface[]> | array
    {
        var relations;

        if !fetch relations, this->belongsToSingle[get_class_lower(model)] {
            return [];
        }

        return relations;
    }

    /**
     * Gets belongsTo related records from a model
     *
     * @param string         $modelName
     * @param string         $modelRelation
     * @param ModelInterface $record
     * @param mixed|null     $parameters
     * @param string|null    $method
     *
     * @return ResultsetInterface | bool
     */
    public function getBelongsToRecords(
        string! modelName,
        string! modelRelation,
        <ModelInterface> record,
        parameters = null,
        string method = null
    ) -> <ResultsetInterface> | bool {
        var relations;
        string keyRelation;

        /**
         * Check if there is a relation between them
         */
        let keyRelation = strtolower(modelName) . "$" . strtolower(modelRelation);

        if !fetch relations, this->hasMany[keyRelation] {
            return false;
        }

        /**
         * "relations" is an array with all the belongsTo relationships to that model
         * Perform the query
         */
        return this->getRelationRecords(
            relations[0],
            record,
            parameters,
            method
        );
    }

    /**
     * Returns the newly created Phalcon\Mvc\Model\Query\Builder or null
     *
     * @return BuilderInterface | null
     */
    public function getBuilder() -> <BuilderInterface> | null
    {
        return this->builder;
    }

    /**
     * Returns the connection service name used to read or write data related to
     * a model depending on the connection services
     *
     * @param ModelInterface $model
     * @param array          $connectionServices
     *
     * @return string
     */
    public function getConnectionService(
        <ModelInterface> model,
        array connectionServices
    ) -> string {
        var connection;

        if !fetch connection, connectionServices[get_class_lower(model)] {
            return "db";
        }

        return connection;
    }

    /**
     * Returns a custom events manager related to a model or null if there is
     * no related events manager
     *
     * @param ModelInterface $model
     *
     * @return EventsManagerInterface | null
     */
    public function getCustomEventsManager(<ModelInterface> model) -> <EventsManagerInterface> | null
    {
        var eventsManager;

        if fetch eventsManager, this->customEventsManager[get_class_lower(model)] {
            return eventsManager;
        }

        return null;
    }

    /**
     * Returns the DependencyInjector container
     */
    public function getDI() -> <DiInterface>
    {
        return this->container;
    }

    /**
     * Returns the internal event manager
     */
    public function getEventsManager() -> <EventsManagerInterface> | null
    {
        return this->eventsManager;
    }

    /**
     * Gets hasMany relations defined on a model
     */
    public function getHasMany(<ModelInterface> model) -> <RelationInterface[]> | array
    {
        var relations;

        if !fetch relations, this->hasManySingle[get_class_lower(model)] {
            return [];
        }

        return relations;
    }

    /**
     * Gets hasMany related records from a model
     */
    public function getHasManyRecords(string! modelName, string! modelRelation, <ModelInterface> record, parameters = null, string method = null)
        -> <ResultsetInterface> | bool
    {
        var relations;
        string keyRelation;

        /**
         * Check if there is a relation between them
         */
        let keyRelation = strtolower(modelName) . "$" . strtolower(modelRelation);

        if !fetch relations, this->hasMany[keyRelation] {
            return false;
        }

        /**
         * "relations" is an array with all the hasMany relationships to that model
         * Perform the query
         */
        return this->getRelationRecords(
            relations[0],
            record,
            parameters,
            method
        );
    }

    /**
     * Gets hasManyToMany relations defined on a model
     */
    public function getHasManyToMany(<ModelInterface> model) -> <RelationInterface[]> | array
    {
        var relations;

        if !fetch relations, this->hasManyToManySingle[get_class_lower(model)] {
            return [];
        }

        return relations;
    }

    /**
     * Gets hasOne relations defined on a model
     */
    public function getHasOne(<ModelInterface> model) -> array
    {
        var relations;

        if !fetch relations, this->hasOneSingle[get_class_lower(model)] {
            return [];
        }

        return relations;
    }

    /**
     * Gets hasOne relations defined on a model
     */
    public function getHasOneAndHasMany(<ModelInterface> model) -> <RelationInterface[]>
    {
        return array_merge(
            this->getHasOne(model),
            this->getHasMany(model)
        );
    }

    /**
     * Gets belongsTo related records from a model
     */
    public function getHasOneRecords(string! modelName, string! modelRelation, <ModelInterface> record, parameters = null, string method = null)
        -> <ModelInterface> | bool
    {
        var relations;
        string keyRelation;

        /**
         * Check if there is a relation between them
         */
        let keyRelation = strtolower(modelName) . "$" . strtolower(modelRelation);

        if !fetch relations, this->hasOne[keyRelation] {
            return false;
        }

        /**
         * "relations" is an array with all the belongsTo relationships to that model
         * Perform the query
         */
        return this->getRelationRecords(
            relations[0],
            record,
            parameters,
            method
        );
    }

    /**
     * Gets hasOneThrough relations defined on a model
     */
    public function getHasOneThrough(<ModelInterface> model) -> <RelationInterface[]> | array
    {
        var relations;

        if !fetch relations, this->hasOneThroughSingle[get_class_lower(model)] {
            return [];
        }

        return relations;
    }

    /**
     * Get last initialized model
     */
    public function getLastInitialized() -> <ModelInterface>
    {
        return this->lastInitialized;
    }

    /**
     * Returns the last query created or executed in the models manager
     */
    public function getLastQuery() -> <QueryInterface>
    {
        return this->lastQuery;
    }

    /**
     * Returns the prefix for all model sources.
     */
    public function getModelPrefix() -> string
    {
        return this->prefix;
    }

    /**
     * Returns the mapped schema for a model
     */
    public function getModelSchema(<ModelInterface> model) -> string | null
    {
        var schema;

        if !fetch schema, this->schemas[get_class_lower(model)] {
            return null;
        }

        return schema;
    }

    /**
     * Returns the mapped source for a model
     */
    public function getModelSource(<ModelInterface> model) -> string
    {
        var entityName;

        let entityName = get_class_lower(model);

        if !isset this->sources[entityName] {
            this->setModelSource(
                model,
                uncamelize(
                    get_class_ns(model)
                )
            );
        }

        return this->prefix . this->sources[entityName];
    }

    /**
     * Returns the connection to read data related to a model
     */
    public function getReadConnection(<ModelInterface> model) -> <AdapterInterface>
    {
        return this->getConnection(model, this->readConnectionServices);
    }

    /**
     * Returns the connection service name used to read data related to a model
     */
    public function getReadConnectionService(<ModelInterface> model) -> string
    {
        return this->getConnectionService(
            model,
            this->readConnectionServices
        );
    }

    /**
     * Returns a relation by its alias
     *
     * @param string modelName
     * @param string alias
     *
     * @return RelationInterface|bool
     */
    public function getRelationByAlias(string! modelName, string! alias) -> <RelationInterface> | bool
    {
        var relation;

        if !fetch relation, this->aliases[strtolower(modelName . "$" . alias)] {
            return false;
        }

        return relation;
    }

    /**
     * Helper method to query records based on a relation definition
     *
     * @param RelationInterface $relation
     * @param ModelInterface    $record
     * @param mixed|null        $parameters
     * @param string|null       $method
     *
     * @return \Phalcon\Mvc\Model\Resultset\Simple|int|false
     */
    public function getRelationRecords(
        <RelationInterface> relation,
        <ModelInterface> record,
        var parameters = null,
        string method = null
    ) {
        var referencedModel, intermediateModel, intermediateFields, fields,
            builder, extraParameters, refPosition, field, referencedFields,
            findParams, findArguments, uniqueKey, records, arguments, rows,
            firstRow, query;
        array placeholders, conditions, joinConditions;
        bool reusable;
        string retrieveMethod;

        /**
         * Re-use bound parameters
         */
        let placeholders = [];

        /**
         * Returns parameters that must be always used when the related records
         * are obtained
         */
        let extraParameters = relation->getParams();

        /**
         * Perform the query on the referenced model
         */
        let referencedModel = relation->getReferencedModel();

        /**
         * Check if the relation is direct or through an intermediate model
         */
        if relation->isThrough() {
            let conditions = [];

            let intermediateModel = relation->getIntermediateModel(),
                intermediateFields = relation->getIntermediateFields();

            /**
             * Appends conditions created from the fields defined in the
             * relation
             */
            let fields = relation->getFields();

            if unlikely typeof fields == "array" {
                throw new Exception("Not supported");
            }

            let conditions[] = "[" . intermediateModel . "].[" . intermediateFields . "] = :APR0:",
                placeholders["APR0"] = record->readAttribute(fields);

            let joinConditions = [];

            /**
             * Create the join conditions
             */
            let intermediateFields = relation->getIntermediateReferencedFields();

            if unlikely typeof intermediateFields == "array" {
                throw new Exception("Not supported");
            }

            let joinConditions[] = "[" . intermediateModel . "].[" . intermediateFields . "] = [" . referencedModel . "].[" . relation->getReferencedFields() . "]";

            /**
             * We don't trust the user or the database so we use bound parameters
             * Create a query builder
             */
            let builder = this->createBuilder(
                this->mergeFindParameters(extraParameters, parameters)
            );

            builder->from(referencedModel);

            builder->innerJoin(
                intermediateModel,
                join(" AND ", joinConditions)
            );

            builder->andWhere(
                join(" AND ", conditions),
                placeholders
            );

            if method == "count" {
                builder->columns("COUNT(*) AS rowcount");

                let rows = builder->getQuery()->execute();

                let firstRow = rows->getFirst();

                return (int) firstRow->readAttribute("rowcount");
            }

            /**
             * Get the query
             */
            let query = <QueryInterface> builder->getQuery();

            switch relation->getType() {
                case Relation::HAS_MANY_THROUGH:
                    return query->execute();

                case Relation::HAS_ONE_THROUGH:
                    return query->setUniqueRow(true)->execute();

                default:
                    throw new Exception("Unknown relation type");
            }
        }

        let conditions = [];

        /**
         * Appends conditions created from the fields defined in the relation
         */
        let fields = relation->getFields();

        /**
         * Compound relation
         */
        let referencedFields = relation->getReferencedFields();

        if typeof fields != "array" {
            let conditions[] = "[" . referencedModel . "].[". referencedFields . "] = :APR0:",
                placeholders["APR0"] = record->readAttribute(fields);
        } else {
            for refPosition, field in relation->getFields() {
                let conditions[] = "[" . referencedModel . "].[". referencedFields[refPosition] . "] = :APR" . refPosition . ":",
                    placeholders["APR" . refPosition] = record->readAttribute(field);
            }
        }

        /**
         * We don't trust the user or data in the database so we use bound parameters
         * Create a valid params array to pass to the find/findFirst method
         */
        let findParams = [
            join(" AND ", conditions),
            "bind"      : placeholders,
            "di"        : record->{"getDi"}()
        ];

        let findArguments = this->mergeFindParameters(findParams, parameters);

        if typeof extraParameters == "array" {
            let findParams = this->mergeFindParameters(
                extraParameters,
                findArguments
            );
        } else {
            let findParams = findArguments;
        }

        /**
         * Check the right method to get the data
         */
        if method === null {
            switch relation->getType() {
                case Relation::BELONGS_TO:
                case Relation::HAS_ONE:
                    let retrieveMethod = "findFirst";
                    break;

                case Relation::HAS_MANY:
                    let retrieveMethod = "find";
                    break;

                default:
                    throw new Exception("Unknown relation type");
            }
        } else {
            let retrieveMethod = method;
        }

        /**
         * Find first results could be reusable
         */
        let reusable = (bool) relation->isReusable();

        if reusable {
            let uniqueKey = unique_key(referencedModel, [findParams, retrieveMethod]),
                records = this->getReusableRecords(referencedModel, uniqueKey);

            if typeof records == "array" || typeof records == "object" {
                return records;
            }
        }

        let arguments = [findParams];

        /**
         * Load the referenced model
         * Call the function in the model
         */
        let records = call_user_func_array(
            [
                this->load(referencedModel),
                retrieveMethod
            ],
            arguments
        );

        /**
         * Store the result in the cache if it's reusable
         */
        if reusable {
            this->setReusableRecords(referencedModel, uniqueKey, records);
        }

        return records;
    }

    /**
     * Query all the relationships defined on a model
     *
     * @param string $modelName
     *
     * @return RelationInterface[]
     */
    public function getRelations(string! modelName) -> <RelationInterface[]>
    {
        var entityName, relations, relation;
        array allRelations;

        let entityName = strtolower(modelName),
            allRelations = [];

        /**
         * Get belongs-to relations
         */
        if fetch relations, this->belongsToSingle[entityName] {
            for relation in relations {
                let allRelations[] = relation;
            }
        }

        /**
         * Get has-many relations
         */
        if fetch relations, this->hasManySingle[entityName] {
            for relation in relations {
                let allRelations[] = relation;
            }
        }

        /**
         * Get has-one relations
         */
        if fetch relations, this->hasOneSingle[entityName] {
            for relation in relations {
                let allRelations[] = relation;
            }
        }

        /**
         * Get has-one-through relations
         */
        if fetch relations, this->hasOneThroughSingle[entityName] {
            for relation in relations {
                let allRelations[] = relation;
            }
        }

        /**
         * Get many-to-many relations
         */
        if fetch relations, this->hasManyToManySingle[entityName] {
            for relation in relations {
                let allRelations[] = relation;
            }
        }

        return allRelations;
    }

    /**
     * Query the first relationship defined between two models
     *
     * @param string $first
     * @param string $second
     *
     * @return RelationInterface[] | bool
     */
    public function getRelationsBetween(string! first, string! second) -> <RelationInterface[]> | bool
    {
        var relations;
        string keyRelation;

        let keyRelation = strtolower(first) . "$" . strtolower(second);

        /**
         * Check if it's a belongs-to relationship
         */
        if fetch relations, this->belongsTo[keyRelation] {
            return relations;
        }

        /**
         * Check if it's a has-many relationship
         */
        if fetch relations, this->hasMany[keyRelation] {
            return relations;
        }

        /**
         * Check whether it's a has-one relationship
         */
        if fetch relations, this->hasOne[keyRelation] {
            return relations;
        }

        /**
         * Check whether it's a has-one-through relationship
         */
        if fetch relations, this->hasOneThrough[keyRelation] {
            return relations;
        }

        /**
        * Check whether it's a has-many-to-many relationship
        */
        if fetch relations, this->hasManyToMany[keyRelation] {
            return relations;
        }

        return false;
    }

    /**
     * Returns a reusable object from the internal list
     *
     * @param string $modelName
     * @param string $key
	 *
	 * @return mixed
     */
    public function getReusableRecords(string! modelName, string! key)
    {
        var records;

        if !fetch records, this->reusable[key] {
            return null;
        }

        return records;
    }

    /**
     * Returns the connection to write data related to a model
     *
     * @param ModelInterface $model
     *
     * @return AdapterInterface
     */
    public function getWriteConnection(<ModelInterface> model) -> <AdapterInterface>
    {
        return this->getConnection(model, this->writeConnectionServices);
    }

    /**
     * Returns the connection service name used to write data related to a model
     *
     * @param ModelInterface $model
     *
     * @return string
     */
    public function getWriteConnectionService(<ModelInterface> model) -> string
    {
        return this->getConnectionService(
            model,
            this->writeConnectionServices
        );
    }

    /**
     * Checks whether a model has a belongsTo relation with another model
     *
     * @param string $modelName
     * @param string $modelRelation
     *
     * @return bool
     */
    public function hasBelongsTo(string! modelName, string! modelRelation) -> bool
    {
        return this->checkHasRelationship("belongsTo", modelName, modelRelation);
    }

    /**
     * Checks whether a model has a hasMany relation with another model
     *
     * @param string $modelName
     * @param string $modelRelation
     *
     * @return bool
     */
    public function hasHasMany(string! modelName, string! modelRelation) -> bool
    {
        return this->checkHasRelationship("hasMany", modelName, modelRelation);
    }

    /**
     * Checks whether a model has a hasManyToMany relation with another model
     *
     * @param string $modelName
     * @param string $modelRelation
     *
     * @return bool
     */
    public function hasHasManyToMany(string! modelName, string! modelRelation) -> bool
    {
        return this->checkHasRelationship("hasManyToMany", modelName, modelRelation);
    }

    /**
     * Checks whether a model has a hasOne relation with another model
     *
     * @param string $modelName
     * @param string $modelRelation
     *
     * @return bool
     */
    public function hasHasOne(string! modelName, string! modelRelation) -> bool
    {
        return this->checkHasRelationship("hasOne", modelName, modelRelation);
    }

    /**
     * Checks whether a model has a hasOneThrough relation with another model
     *
     * @param string $modelName
     * @param string $modelRelation
     *
     * @return bool
     */
    public function hasHasOneThrough(string! modelName, string! modelRelation) -> bool
    {
        return this->checkHasRelationship("hasOneThrough", modelName, modelRelation);
    }

    /**
     * Initializes a model in the model manager
     *
     * @param ModelInterface $model
     *
     * @return bool
     */
    public function initialize(<ModelInterface> model) -> bool
    {
        var className, eventsManager;

        let className = get_class_lower(model);

        /**
         * Models are just initialized once per request
         */
        if isset this->initialized[className] {
            return false;
        }

        /**
         * Update the model as initialized, this avoid cyclic initializations
         */
        let this->initialized[className] = true;

        /**
         * Call the 'initialize' method if it's implemented
         */
        if method_exists(model, "initialize") {
            model->{"initialize"}();
        }

        /**
         * Update the last initialized model, so it can be used in
         * modelsManager:afterInitialize
         */
        let this->lastInitialized = model;

        /**
         * If an EventsManager is available we pass to it every initialized
         * model
         */
        let eventsManager = <EventsManagerInterface> this->eventsManager;

        if typeof eventsManager == "object" {
            eventsManager->fire("modelsManager:afterInitialize", this, model);
        }

        return true;
    }

    /**
     * Check whether a model is already initialized
     *
     * @param string $className
     *
     * @return bool
     */
    public function isInitialized(string! className) -> bool
    {
        return isset this->initialized[strtolower(className)];
    }

    /**
     * Checks if a model is keeping snapshots for the queried records
     *
     * @param ModelInterface $model
     *
     * @return bool
     */
    public function isKeepingSnapshots(<ModelInterface> model) -> bool
    {
        var isKeeping;

        if globals_get("orm.dynamic_update") {
            return true;
        }

        if !fetch isKeeping, this->keepSnapshots[get_class_lower(model)] {
            return false;
        }

        return isKeeping;
    }

    /**
     * Checks if a model is using dynamic update instead of all-field update
     *
     * @param ModelInterface $model
     *
     * @return bool
     */
    public function isUsingDynamicUpdate(<ModelInterface> model) -> bool
    {
        var isUsing;

        if globals_get("orm.dynamic_update") {
            return true;
        }

        if !fetch isUsing, this->dynamicUpdate[get_class_lower(model)] {
            return false;
        }

        return isUsing;
    }

    /**
     * Check whether a model property is declared as public.
     *
     * ```php
     * $isPublic = $manager->isVisibleModelProperty(
     *     new Robots(),
     *     "name"
     * );
     * ```
     *
     * @param ModelInterface $model
     * @param string         $property
     *
     * @return bool
     */
    final public function isVisibleModelProperty(<ModelInterface> model, string property) -> bool
    {
        var properties, className, publicProperties, classReflection,
            reflectionProperties, reflectionProperty;

        let className = get_class(model);

        if !isset this->modelVisibility[className] {
            let publicProperties = [];
            let classReflection = new ReflectionClass(className);
            let reflectionProperties = classReflection->getProperties(ReflectionProperty::IS_PUBLIC);
            for reflectionProperty in reflectionProperties {
                let publicProperties[reflectionProperty->name] = true;
            }
            let this->modelVisibility[className] = publicProperties;
        }

        let properties = this->modelVisibility[className];

        return array_key_exists(property, properties);
    }

    /**
     * Sets if a model must keep snapshots
     *
     * @param ModelInterface $model
     * @param bool           $keepSnapshots
     *
     * @return void
     */
    public function keepSnapshots(<ModelInterface> model, bool keepSnapshots) -> void
    {
        let this->keepSnapshots[get_class_lower(model)] = keepSnapshots;
    }

    /**
     * Loads a model throwing an exception if it doesn't exist
     *
     * @param string $modelName
     *
     * @return ModelInterface
     */
    public function load(string! modelName) -> <ModelInterface>
    {
        var model;

        /**
         * The model doesn't exist throw an exception
         */
        if unlikely !class_exists(modelName) {
            throw new Exception(
                "Model '" . modelName . "' could not be loaded"
            );
        }

        /**
         * Load it using an autoloader
         */
        let model = create_instance_params(
            modelName,
            [
                null,
                this->container,
                this
            ]
        );

        return model;
    }

    /**
     * Receives events generated in the models and dispatches them to an
     * events-manager if available. Notify the behaviors that are listening in
     * the model
     *
     * @param string         $eventName
     * @param ModelInterface $model
     */
    public function notifyEvent(string! eventName, <ModelInterface> model)
    {
        var status, behavior, modelsBehaviors, eventsManager,
            customEventsManager;

        let status = true;

        /**
         * Dispatch events to the global events manager
         */
        if fetch modelsBehaviors, this->behaviors[get_class_lower(model)] {
            /**
             * Notify all the events on the behavior
             */
            for behavior in modelsBehaviors {
                let status = behavior->notify(eventName, model);

                if status === false {
                    return false;
                }
            }
        }

        /**
         * Dispatch events to the global events manager
         */
        let eventsManager = this->eventsManager;

        if typeof eventsManager == "object" {
            let status = eventsManager->fire(
                "model:" . eventName,
                model
            );

            if status === false {
                return status;
            }
        }

        /**
         * A model can has a specific events manager for it
         */
        if fetch customEventsManager, this->customEventsManager[get_class_lower(model)] {
            let status = customEventsManager->fire(
                "model:" . eventName,
                model
            );

            if status === false {
                return false;
            }
        }

        return status;
    }

    /**
     * Dispatch an event to the listeners and behaviors
     * This method expects that the endpoint listeners/behaviors returns true
     * meaning that a least one was implemented
     *
     * @param ModelInterface $model
     * @param string         $eventName
     * @param mixed          $data
     */
    public function missingMethod(<ModelInterface> model, string! eventName, var data)
    {
        var modelsBehaviors, result, eventsManager, behavior;

        /**
         * Dispatch events to the global events manager
         */
        if fetch modelsBehaviors, this->behaviors[get_class_lower(model)] {
            /**
             * Notify all the events on the behavior
             */
            for behavior in modelsBehaviors {
                let result = behavior->missingMethod(model, eventName, data);

                if result !== null {
                    return result;
                }
            }
        }

        /**
         * Dispatch events to the global events manager
         */
        let eventsManager = this->eventsManager;

        if typeof eventsManager == "object" {
            return eventsManager->fire(
                "model:" . eventName,
                model,
                data
            );
        }

        return null;
    }

    /**
     * Sets both write and read connection service for a model
     *
     * @param ModelInterface $model
     * @param string         $connectionService
     *
     * @return void
     */
    public function setConnectionService(<ModelInterface> model, string! connectionService) -> void
    {
        this->setReadConnectionService(model, connectionService);
        this->setWriteConnectionService(model, connectionService);
    }

    /**
     * Sets a custom events manager for a specific model
     *
     * @param ModelInterface         $model
     * @param EventsManagerInterface $eventsManager
     *
     * @return void
     */
    public function setCustomEventsManager(<ModelInterface> model, <EventsManagerInterface> eventsManager) -> void
    {
        let this->customEventsManager[get_class_lower(model)] = eventsManager;
    }

    /**
     * Sets the DependencyInjector container
     *
     * @param DiInterface $container
     *
     * @return void
     */
    public function setDI(<DiInterface> container) -> void
    {
        let this->container = container;
    }

    /**
     * Sets a global events manager
     *
     * @param EventsManagerInterface $eventsManager
     *
     * @return void
     */
    public function setEventsManager(<EventsManagerInterface> eventsManager) -> void
    {
        let this->eventsManager = eventsManager;
    }

    /**
     * Sets the prefix for all model sources.
     *
     * ```php
     * use Phalcon\Mvc\Model\Manager;
     *
     * $di->set(
     *     "modelsManager",
     *     function () {
     *         $modelsManager = new Manager();
     *
     *         $modelsManager->setModelPrefix("wp_");
     *
     *         return $modelsManager;
     *     }
     * );
     *
     * $robots = new Robots();
     *
     * echo $robots->getSource(); // wp_robots
     * ```
     *
     * $param string $prefix
     *
     * @return void
     */
    public function setModelPrefix(string! prefix) -> void
    {
        let this->prefix = prefix;
    }

    /**
     * Sets the mapped schema for a model
     *
     * @param ModelInterface $model
     * @param string         $schema
     *
     * @return void
     */
    public function setModelSchema(<ModelInterface> model, string! schema) -> void
    {
        let this->schemas[get_class_lower(model)] = schema;
    }

    /**
     * Sets the mapped source for a model
     *
     * @param ModelInterface $model
     * @param string         $source
     *
     * @return void
     */
    public function setModelSource(<ModelInterface> model, string! source) -> void
    {
        let this->sources[get_class_lower(model)] = source;
    }

    /**
     * Sets read connection service for a model
     *
     * @param ModelInterface $model
     * @param string         $connectionService
     *
     * @return void
     */
    public function setReadConnectionService(<ModelInterface> model, string! connectionService) -> void
    {
        let this->readConnectionServices[get_class_lower(model)] = connectionService;
    }

    /**
     * Stores a reusable record in the internal list
     *
     * @param ModelInterface $model
     * @param string         $key
     * @param mixed          $records
     *
     * @return void
     */
    public function setReusableRecords(string! modelName, string! key, var records) -> void
    {
        let this->reusable[key] = records;
    }

    /**
     * Sets write connection service for a model
     *
     * @param ModelInterface $model
     * @param string         $connectionService
     *
     * @return void
     */
    public function setWriteConnectionService(<ModelInterface> model, string! connectionService) -> void
    {
        let this->writeConnectionServices[get_class_lower(model)] = connectionService;
    }

    /**
     * Sets if a model must use dynamic update instead of the all-field update
     *
     * @param ModelInterface $model
     * @param bool           $dynamicUpdate
     *
     * @return void
     */
    public function useDynamicUpdate(<ModelInterface> model, bool dynamicUpdate) -> void
    {
        var entityName;

        let entityName = get_class_lower(model),
            this->dynamicUpdate[entityName] = dynamicUpdate,
            this->keepSnapshots[entityName] = dynamicUpdate;
    }

    /**
     * Returns the connection to read or write data related to a model
     * depending on the connection services.
     *
     * @param ModelInterface $model
     * @param array          $connectionServices
     *
     * @return AdapterInterface
     */
    protected function getConnection(
        <ModelInterface> model,
        array connectionServices
    ) -> <AdapterInterface> {
        var container, service, connection;

        let service = this->getConnectionService(model, connectionServices);

        let container = <DiInterface> this->container;

        if unlikely typeof container != "object" {
            throw new Exception(
                "A dependency injection container is required to access the services related to the ORM"
            );
        }

        /**
         * Request the connection service from the DI
         */
        let connection = <AdapterInterface> container->getShared(service);

        if unlikely typeof connection != "object" {
            throw new Exception("Invalid injected connection service");
        }

        return connection;
    }

    /**
     * Merge two arrays of find parameters
     *
     * @param mixed $findParamsOne
     * @param mixed $findParamsTwo
     *
     * @return array
     */
    final protected function mergeFindParameters(var findParamsOne, var findParamsTwo) -> array
    {
        var key, value;
        array findParams;

        let findParams = [];

        if typeof findParamsOne == "string" {
            let findParamsOne = [
                "conditions": findParamsOne
            ];
        }

        if typeof findParamsTwo == "string" {
            let findParamsTwo = [
                "conditions": findParamsTwo
            ];
        }

        if typeof findParamsOne == "array"  {
            for key, value in findParamsOne {
                if key === 0 || key === "conditions" {
                    if !isset findParams[0] {
                        let findParams[0] = value;
                    } else {
                        let findParams[0] = "(" . findParams[0] . ") AND (" . value . ")";
                    }
                } else {
                    let findParams[key] = value;
                }
            }
        }

        if typeof findParamsTwo == "array"  {
            for key, value in findParamsTwo {
                if key === 0 || key === "conditions" {
                    if !isset findParams[0] {
                        let findParams[0] = value;
                    } else {
                        let findParams[0] = "(" . findParams[0] . ") AND (" . value . ")";
                    }
                } elseif key === "bind" || key === "bindTypes" {
                    if typeof value == "array" {
                        if !isset findParams[key] {
                            let findParams[key] = value;
                        } else {
                            let findParams[key] = array_merge(
                                findParams[key],
                                value
                            );
                        }
                    }
                } else {
                    let findParams[key] = value;
                }
            }
        }

        return findParams;
    }

    /**
     * @param string $collection
     * @param string $modelName
     * @param string $modelRelation
     *
     * @return bool
     */
    private function checkHasRelationship(
        string collection,
        string! modelName,
        string! modelRelation
    ) -> bool {
        var entityName;
        string keyRelation;

        let entityName = strtolower(modelName);

        /**
         * Relationship unique key
         */
        let keyRelation = entityName . "$" . strtolower(modelRelation);

        /**
         * Initialize the model first
         */
        if !isset this->initialized[entityName] {
            this->load(modelName);
        }

        return isset this->{collection}[keyRelation];
    }

    /**
     * Sets a cache for model working in memory
     */
    public function hasSessionCache() -> bool
    {
        return this->sessionCache !== null;
    }
 
 
     /**
      * Sets a cache for model working in memory
      */
    public function setSessionCache(<AbstractAdapter> cache) -> void
    {
        let this->sessionCache = cache;
    }
 
     /**
      * Returns a cache instance or null if not configured
      */
    public function getSessionCache() -> <AbstractAdapter> | null
    {
        return this->sessionCache;
    }

}
