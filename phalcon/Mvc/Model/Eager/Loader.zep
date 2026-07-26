
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Eager;

use Phalcon\Mvc\Model\Exceptions\EagerRowLimitExceeded;
use Phalcon\Mvc\Model\Exceptions\MissingEagerKeyColumn;
use Phalcon\Mvc\Model\Exceptions\UnknownEagerRelation;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Mvc\Model\ManagerInterface;
use Phalcon\Mvc\Model\Relation;
use Phalcon\Mvc\Model\RelationInterface;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Mvc\ModelInterface;

/**
 * Loads model relations in bulk - a bounded number of queries per relation
 * node rather than one per record - and applies the result to records as they
 * are hydrated.
 */
class Loader
{
    /**
     * Maximum number of rows a single relation node may return before the load
     * is refused. Guards against a to-many hop that follows a to-one hop, which
     * can fan out to an entire table.
     */
    const MAX_ROWS_PER_LEVEL = 100000;

    /**
     * @var ManagerInterface
     */
    protected manager;

    public function __construct(<ManagerInterface> manager)
    {
        let this->manager = manager;
    }

    /**
     * Applies a pre-built eager map to a single record.
     *
     * Shared by Resultset\Simple::current(), which stamps records as they are
     * hydrated, and by the loader itself, which stamps instances it retains.
     *
     * Both Model and Row implement readAttribute(), so key extraction is
     * uniform; only the write differs. A Row is what a column-restricted
     * select produces, and it has no relation cache.
     *
     * @param object $record ModelInterface or Row
     */
    public static function apply(var record, array eagerMap) -> void
    {
        var alias, field, fields, lookup, node, records, related;
        array values;

        for alias, node in eagerMap {
            let fields = node["fields"],
                values = [];

            for field in fields {
                let values[] = record->readAttribute(field);
            }

            let records = node["records"],
                related = node["empty"];

            if !in_array(null, values, true) {
                let lookup = self::buildKey(values);

                if isset records[lookup] {
                    let related = records[lookup];
                }
            }

            if record instanceof ModelInterface {
                record->setRelated(alias, related);
            } else {
                record->writeAttribute(alias, related);
            }
        }
    }

    /**
     * Builds the lookup key for a set of key-field values.
     *
     * Always a string. A single value is cast, which also neutralizes the
     * PostgreSQL-integer / MySQL-string mismatch for the same column. Multiple
     * values are length-prefixed so ["a|b", "c"] cannot collide with
     * ["a", "b|c"].
     */
    public static function buildKey(array values) -> string
    {
        var part, value;
        string key;

        if count(values) === 1 {
            return (string) values[0];
        }

        let key = "";

        for value in values {
            let part = (string) value,
                key  = key . strlen(part) . ":" . part;
        }

        return key;
    }

    /**
     * Loads a relation tree for a root resultset.
     *
     * The resultset is materialized first: at this point the statement has run
     * but no row has been consumed, so fetching every row costs nothing extra
     * and gives the key values without a second pass over the cursor.
     */
    public function loadResultset(
        <Simple> resultset,
        string modelName,
        array tree
    ) -> void {
        if count(tree) === 0 || resultset->count() === 0 {
            return;
        }

        resultset->materialize();

        resultset->setEagerMap(
            this->buildMap(resultset->toArray(), modelName, tree)
        );
    }

    /**
     * Builds one level of the map.
     *
     * @param array $parents attribute-keyed row arrays at the root, or
     *                       ModelInterface / Row instances below it
     */
    protected function buildMap(
        array parents,
        string modelName,
        array tree
    ) -> array {
        var alias, node, relation;
        array map;

        let map = [];

        for alias, node in tree {
            let relation = this->manager->getRelationByAlias(modelName, alias);

            if unlikely typeof relation !== "object" {
                throw new UnknownEagerRelation(modelName, alias);
            }

            let map[strtolower(alias)] = this->buildNode(
                relation,
                alias,
                parents,
                node
            );
        }

        return map;
    }

    /**
     * Builds a single map node: one query, indexed by the referenced field.
     */
    protected function buildNode(
        <RelationInterface> relation,
        string alias,
        array parents,
        array node
    ) -> array {
        var childMap, children, emptyResult, fields, keys, keyValue, position,
            positions, record, referencedFields, sub, children2;
        array childModels, index, records;
        bool isMany;

        if relation->isThrough() {
            return this->buildThroughNode(relation, alias, parents, node);
        }

        let fields = this->normalizeFields(relation->getFields());

        let referencedFields = this->normalizeFields(
            relation->getReferencedFields()
        );

        let keys = this->collectKeys(parents, fields, alias);

        let children = this->fetchReferenced(
            relation,
            alias,
            keys,
            node["options"]
        );

        let childModels = [],
            index       = [],
            position    = 0;

        children->rewind();

        while children->valid() {
            let record = children->current();

            let childModels[] = record;

            let keyValue = this->recordKey(record, referencedFields);

            let index[keyValue][] = position;

            let position++;

            children->next();
        }

        let isMany      = relation->getType() === Relation::HAS_MANY,
            emptyResult = isMany ? children->sliceRows([]) : null;

        let records = [];

        for keyValue, positions in index {
            if isMany {
                let records[keyValue] = children->sliceRows(positions);
            } else {
                let records[keyValue] = childModels[positions[0]];
            }
        }

        /**
         * Levels below the root are cheaper than the root: the loader is
         * holding real instances it built itself, so there is no transient
         * hydration to work around.
         */
        if count(node["children"]) > 0 && count(childModels) > 0 {
            let childMap = this->buildMap(
                childModels,
                relation->getReferencedModel(),
                node["children"]
            );

            if isMany {
                /**
                 * The caller never sees `childModels` for a to-many relation -
                 * the slices hydrate their own instances - so the map has to
                 * travel with the slices.
                 */
                for keyValue, sub in records {
                    let children2 = sub;

                    children2->setEagerMap(childMap);
                }

                emptyResult->setEagerMap(childMap);
            } else {
                for record in childModels {
                    self::apply(record, childMap);
                }
            }
        }

        return [
            "fields"  : fields,
            "records" : records,
            "empty"   : emptyResult
        ];
    }

    /**
     * Through-relations in two steps rather than a join.
     *
     * Step one fetches (parentKey, referencedKey) pairs from the intermediate
     * model; step two fetches the referenced rows for the keys those pairs
     * collected. The pairs then attribute referenced rows back to parents
     * without a synthetic column in the select list, and without the row
     * multiplication an inner join would cause.
     */
    protected function buildThroughNode(
        <RelationInterface> relation,
        string alias,
        array parents,
        array node
    ) -> array {
        var childMap, emptyResult, fields, intermediateField, intermediateFields,
            intermediateModel, intermediateReferencedField,
            intermediateReferencedFields, keyValue, keys, pair, pairs, parentKey,
            position, positions, record, referenced, referencedFields,
            referencedKey, referencedKeys, slice, sub, tuple;
        array childModels, index, pairMap, records;
        bool isMany;

        let fields             = this->normalizeFields(relation->getFields()),
            intermediateFields = this->normalizeFields(
                relation->getIntermediateFields()
            ),
            referencedFields   = this->normalizeFields(
                relation->getReferencedFields()
            );

        let intermediateReferencedFields = this->normalizeFields(
            relation->getIntermediateReferencedFields()
        );

        let intermediateField           = intermediateFields[0],
            intermediateReferencedField = intermediateReferencedFields[0],
            intermediateModel           = relation->getIntermediateModel();

        let isMany = relation->getType() === Relation::HAS_MANY_THROUGH;

        let keys = this->collectKeys(parents, fields, alias);

        let pairMap        = [],
            referencedKeys = [];

        if count(keys) > 0 {
            /**
             * Step one - the intermediate pairs. Only the two key columns are
             * selected, so these come back as Row objects.
             */
            let pairs = call_user_func_array(
                [this->manager->load(intermediateModel), "find"],
                [
                    [
                        "[" . intermediateField . "] IN ({phEagerKeys:array})",
                        "columns": intermediateField . ", "
                            . intermediateReferencedField,
                        "bind": ["phEagerKeys": array_column(keys, 0)]
                    ]
                ]
            );

            pairs->rewind();

            while pairs->valid() {
                let pair = pairs->current();

                let parentKey = self::buildKey(
                    [pair->readAttribute(intermediateField)]
                );

                let referencedKey = self::buildKey(
                    [pair->readAttribute(intermediateReferencedField)]
                );

                let pairMap[parentKey][]        = referencedKey;
                let referencedKeys[referencedKey] = [
                    pair->readAttribute(intermediateReferencedField)
                ];

                pairs->next();
            }
        }

        /**
         * Step two - the referenced rows for the collected keys.
         */
        let referenced = this->fetchReferenced(
            relation,
            alias,
            array_values(referencedKeys),
            node["options"]
        );

        let childModels = [],
            index       = [],
            position    = 0;

        referenced->rewind();

        while referenced->valid() {
            let record = referenced->current();

            let childModels[] = record;

            let keyValue = this->recordKey(record, referencedFields);

            let index[keyValue][] = position;

            let position++;

            referenced->next();
        }

        let emptyResult = isMany ? referenced->sliceRows([]) : null;

        let records = [];

        for parentKey, positions in pairMap {
            let tuple = [];

            for referencedKey in positions {
                if fetch sub, index[referencedKey] {
                    let tuple = array_merge(tuple, sub);
                }
            }

            if count(tuple) === 0 {
                continue;
            }

            if isMany {
                let records[parentKey] = referenced->sliceRows(tuple);
            } else {
                let records[parentKey] = childModels[tuple[0]];
            }
        }

        if count(node["children"]) > 0 && count(childModels) > 0 {
            let childMap = this->buildMap(
                childModels,
                relation->getReferencedModel(),
                node["children"]
            );

            if isMany {
                for keyValue, sub in records {
                    let slice = sub;

                    slice->setEagerMap(childMap);
                }

                emptyResult->setEagerMap(childMap);
            } else {
                for record in childModels {
                    self::apply(record, childMap);
                }
            }
        }

        return [
            "fields"  : fields,
            "records" : records,
            "empty"   : emptyResult
        ];
    }

    /**
     * Distinct, non-null local key tuples across the parent set.
     *
     * @param array $parents attribute-keyed row arrays, ModelInterface or Row
     *
     * @return array list of value-tuples, deduped
     */
    protected function collectKeys(
        array parents,
        array fields,
        string alias
    ) -> array {
        var field, parent, value;
        array seen, values;

        let seen = [];

        for parent in parents {
            let values = [];

            for field in fields {
                if typeof parent === "object" {
                    let value = parent->readAttribute(field);
                } else {
                    if unlikely !array_key_exists(field, parent) {
                        throw new MissingEagerKeyColumn(alias, field);
                    }

                    let value = parent[field];
                }

                let values[] = value;
            }

            if in_array(null, values, true) {
                continue;
            }

            let seen[self::buildKey(values)] = values;
        }

        return array_values(seen);
    }

    /**
     * One query per relation node. An empty key set issues none at all -
     * WHERE IN () is a syntax error and there is nothing to attribute.
     */
    protected function fetchReferenced(
        <RelationInterface> relation,
        string alias,
        array keys,
        array options
    ) -> <Simple> {
        var binds, columnList, columns, extraParameters, fieldIndex, groups,
            keyIndex, modelInstance, parts, placeholder, referencedField,
            referencedFields, referencedModel, resultset, tuple;
        array findParams;

        let referencedModel = relation->getReferencedModel(),
            modelInstance   = this->manager->load(referencedModel);

        if count(keys) === 0 {
            return new Simple(null, modelInstance, false);
        }

        let referencedFields = this->normalizeFields(
            relation->getReferencedFields()
        );

        if count(referencedFields) === 1 {
            let referencedField = referencedFields[0];

            let findParams = [
                "[" . referencedField . "] IN ({phEagerKeys:array})",
                "bind": ["phEagerKeys": array_column(keys, 0)]
            ];
        } else {
            /**
             * Row-value predicates - (a, b) IN ((1, 2)) - are not supported
             * uniformly across MySQL, PostgreSQL and SQLite, so composite keys
             * are expressed as OR-grouped equality instead.
             */
            let binds    = [],
                groups   = [],
                keyIndex = 0;

            for tuple in keys {
                let parts = [];

                for fieldIndex, referencedField in referencedFields {
                    let placeholder = "phEagerKey" . keyIndex . "_" . fieldIndex;

                    let parts[] = "[" . referencedField . "] = :"
                        . placeholder . ":";

                    let binds[placeholder] = tuple[fieldIndex];
                }

                let groups[] = "(" . join(" AND ", parts) . ")";

                let keyIndex++;
            }

            let findParams = [
                join(" OR ", groups),
                "bind": binds
            ];
        }

        /**
         * A relation may carry conditions of its own. Ignoring them returns
         * unfiltered children - wrong data that no query-count assertion would
         * catch. getParams() returns false when unset (Relation.zep:213) and
         * invokes a closure before returning (:206); the closure takes no
         * arguments, so evaluating it once per batch is equivalent.
         *
         * The eager predicate is passed as the second argument in both merges
         * so that its bindings survive - mergeFindParameters() only merges the
         * second argument's `bind` entry.
         */
        let extraParameters = relation->getParams();

        if typeof extraParameters === "array" {
            let findParams = Manager::mergeFindParameters(
                extraParameters,
                findParams
            );
        }

        if count(options) > 0 {
            let findParams = Manager::mergeFindParameters(options, findParams);
        }

        /**
         * A restricted column list that omits the join key leaves every
         * returned row unattributable. Refuse rather than inject a column the
         * caller did not ask for - it would surface in the returned Row.
         */
        if fetch columns, findParams["columns"] {
            if typeof columns === "array" {
                let columnList = join(",", columns);
            } else {
                let columnList = (string) columns;
            }

            let columnList = str_replace(" ", "", columnList);

            for referencedField in referencedFields {
                if unlikely false === strpos(columnList, referencedField) {
                    throw new MissingEagerKeyColumn(alias, referencedField);
                }
            }
        }

        let resultset = call_user_func_array(
            [modelInstance, "find"],
            [findParams]
        );

        resultset->materialize();

        if unlikely resultset->count() > self::MAX_ROWS_PER_LEVEL {
            throw new EagerRowLimitExceeded(
                referencedModel,
                resultset->count(),
                self::MAX_ROWS_PER_LEVEL
            );
        }

        return resultset;
    }

    /**
     * Relation fields are declared as a string for a single column and an
     * array for a composite key. Normalizing removes that fork everywhere
     * downstream.
     */
    protected function normalizeFields(var fields) -> array
    {
        if typeof fields === "array" {
            return fields;
        }

        return [fields];
    }

    /**
     * Lookup key for an already-hydrated record.
     */
    protected function recordKey(var record, array fields) -> string
    {
        var field;
        array values;

        let values = [];

        for field in fields {
            let values[] = record->readAttribute(field);
        }

        return self::buildKey(values);
    }
}
