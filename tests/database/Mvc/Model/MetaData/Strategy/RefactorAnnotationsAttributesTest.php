<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model\MetaData\Strategy;

use Phalcon\Annotations\AttributesReader;
use Phalcon\Db\Column;
use Phalcon\Mvc\Model\MetaData;
use Phalcon\Mvc\Model\MetaData\Strategy\Annotations;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Annotations\Robot;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class RefactorAnnotationsAttributesTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();

        /**
         * Same model, same assertions, the attributes reader instead of the
         * docblock one. The model carries the two forms side by side.
         */
        $annotations = $this->container->get("annotations");
        $annotations->setReader(new AttributesReader());
    }

    /**
     * The per-column flags land in the matching metadata indexes. The
     * attribute uses the camelCase argument names, which the strategy reads
     * next to the snake_case ones of the docblock.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-20
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelMetadataStrategyAnnotationsColumnFlags(): void
    {
        $strategy = new Annotations();
        $model    = new Robot();

        $metaData = $strategy->getMetaData($model, $this->container);

        $this->assertSame(['id'], $metaData[MetaData::MODELS_PRIMARY_KEY]);
        $this->assertSame('id', $metaData[MetaData::MODELS_IDENTITY_COLUMN]);

        $this->assertSame(
            ['deleted' => true],
            $metaData[MetaData::MODELS_AUTOMATIC_DEFAULT_INSERT]
        );

        $this->assertSame(
            ['float' => true, 'longblob' => true],
            $metaData[MetaData::MODELS_AUTOMATIC_DEFAULT_UPDATE]
        );

        $this->assertSame(
            ['name' => 'name', 'text' => 'text'],
            $metaData[MetaData::MODELS_EMPTY_STRING_VALUES]
        );

        /**
         * A column keeps its default value. A nullable column has the
         * default null, even when the attribute gives no default.
         *
         * `year` is an int here and a string in the docblock test. The
         * parser stores every literal as a string, while PHP resolves an
         * attribute argument to its real type. The two flavors agree on the
         * value and not on the type.
         */
        $defaults = $metaData[MetaData::MODELS_DEFAULT_VALUES];
        $this->assertSame('mechanical', $defaults['type']);
        $this->assertSame(1900, $defaults['year']);
        $this->assertNull($defaults['json']);
        $this->assertArrayNotHasKey('name', $defaults);

        /**
         * The nullable columns are the only ones that are not in the
         * not-null list.
         */
        $notNull = $metaData[MetaData::MODELS_NOT_NULL];
        $this->assertContains('name', $notNull);
        $this->assertNotContains('deleted', $notNull);
        $this->assertNotContains('json', $notNull);

        $this->assertSame('text', $metaData[MetaData::MODELS_ATTRIBUTES][5]);
        $this->assertNotContains('id', $metaData[MetaData::MODELS_NON_PRIMARY_KEY]);
    }

    /**
     * The `column` argument remaps the property to another column name
     * (`description` -> `text`), and only that difference makes the strategy
     * return a column map.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-19
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelMetadataStrategyAnnotationsColumnMaps(): void
    {
        $strategy = new Annotations();
        $model    = new Robot();

        [$ordered, $reversed] = $strategy->getColumnMaps($model, $this->container);

        $this->assertSame('description', $ordered['text']);
        $this->assertSame('text', $reversed['description']);
        $this->assertSame('id', $ordered['id']);
        $this->assertSame('id', $reversed['id']);
    }

    /**
     * Every `type` the strategy knows maps to a column type, a bind type,
     * and, for the number types, to the numeric-typed index. A type it does
     * not know falls back to varchar.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-19
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelMetadataStrategyAnnotationsColumnTypes(): void
    {
        $strategy = new Annotations();
        $model    = new Robot();

        $metaData = $strategy->getMetaData($model, $this->container);

        $types = $metaData[MetaData::MODELS_DATA_TYPES];
        $binds = $metaData[MetaData::MODELS_DATA_TYPES_BIND];

        $expectedTypes = [
            'id'         => Column::TYPE_BIGINTEGER,
            'name'       => Column::TYPE_VARCHAR,
            'year'       => Column::TYPE_INTEGER,
            'deleted'    => Column::TYPE_DATETIME,
            'text'       => Column::TYPE_TEXT,
            'float'      => Column::TYPE_FLOAT,
            'double'     => Column::TYPE_DOUBLE,
            'decimal'    => Column::TYPE_DECIMAL,
            'activated'  => Column::TYPE_BOOLEAN,
            'birthday'   => Column::TYPE_DATE,
            'timestamp'  => Column::TYPE_TIMESTAMP,
            'duration'   => Column::TYPE_TIME,
            'code'       => Column::TYPE_CHAR,
            'bit'        => Column::TYPE_BIT,
            'enum'       => Column::TYPE_ENUM,
            'tinyint'    => Column::TYPE_TINYINTEGER,
            'smallint'   => Column::TYPE_SMALLINTEGER,
            'mediumint'  => Column::TYPE_MEDIUMINTEGER,
            'tinytext'   => Column::TYPE_TINYTEXT,
            'mediumtext' => Column::TYPE_MEDIUMTEXT,
            'longtext'   => Column::TYPE_LONGTEXT,
            'json'       => Column::TYPE_JSON,
            'jsonb'      => Column::TYPE_JSONB,
            'tinyblob'   => Column::TYPE_TINYBLOB,
            'blob'       => Column::TYPE_BLOB,
            'mediumblob' => Column::TYPE_MEDIUMBLOB,
            'longblob'   => Column::TYPE_LONGBLOB,
        ];

        foreach ($expectedTypes as $column => $expected) {
            $this->assertSame($expected, $types[$column], $column);
        }

        $expectedBinds = [
            'id'        => Column::BIND_PARAM_STR,
            'year'      => Column::BIND_PARAM_INT,
            'float'     => Column::BIND_PARAM_DECIMAL,
            'double'    => Column::BIND_PARAM_DECIMAL,
            'decimal'   => Column::BIND_PARAM_DECIMAL,
            'activated' => Column::BIND_PARAM_BOOL,
            'bit'       => Column::BIND_PARAM_INT,
            'tinyint'   => Column::BIND_PARAM_INT,
            'smallint'  => Column::BIND_PARAM_INT,
            'mediumint' => Column::BIND_PARAM_INT,
            'blob'      => Column::BIND_PARAM_BLOB,
            'tinyblob'  => Column::BIND_PARAM_BLOB,
            'longblob'  => Column::BIND_PARAM_BLOB,
            'name'      => Column::BIND_PARAM_STR,
        ];

        foreach ($expectedBinds as $column => $expected) {
            $this->assertSame($expected, $binds[$column], $column);
        }

        $numeric = $metaData[MetaData::MODELS_DATA_TYPES_NUMERIC];
        $this->assertArrayHasKey('id', $numeric);
        $this->assertArrayHasKey('enum', $numeric);
        $this->assertArrayNotHasKey('name', $numeric);
        $this->assertArrayNotHasKey('blob', $numeric);
    }
}
