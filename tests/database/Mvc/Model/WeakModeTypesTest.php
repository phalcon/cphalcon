<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model;

use PDO;
use Phalcon\Db\Column;
use Phalcon\Mvc\Model;
use Phalcon\Support\Settings;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\CustomersDefaultsMigration;
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\CustomersDefaultsTyped;
use Phalcon\Tests\Support\Models\InvoicesWeakTypesPublic;
use Phalcon\Tests\Support\Models\InvoicesWeakTypesSetters;
use Phalcon\Tests\Support\Models\InvoicesWithSetters;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;
use TypeError;

/**
 * The ORM gives values to typed setters and typed properties with the PHP
 * weak type rules, the same as cphalcon. The test file declares
 * strict_types=1, so the mode of the caller has no effect.
 */
final class WeakModeTypesTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        /** @var PDO $connection */
        $connection = self::getPdoConnection();
        (new InvoicesMigration($connection));
        (new CustomersMigration($connection));
        (new CustomersDefaultsMigration($connection));
    }

    public function tearDown(): void
    {
        Settings::reset();

        parent::tearDown();
    }

    /**
     * @return array<string, array{0: string, 1: mixed}>
     */
    public static function getRefusedValues(): array
    {
        return [
            'int from text'          => ['inv_id', 'abc'],
            'int from empty string'  => ['inv_id', ''],
            'non-null int from null' => ['inv_cst_id', null],
        ];
    }

    /**
     * @return array<string, array{0: string, 1: mixed, 2: mixed}>
     */
    public static function getWeakValues(): array
    {
        return [
            'int from string'          => ['inv_id', '42', 42],
            'int from padded string'   => ['inv_id', ' 42 ', 42],
            'non-null int from string' => ['inv_cst_id', '42', 42],
            'float from string'        => ['inv_total', '4.5', 4.5],
            'string from int'          => ['inv_title', 1, '1'],
            'bool from one'            => ['inv_status_flag', '1', true],
            'bool from zero'           => ['inv_status_flag', '0', false],
            'int from null'            => ['inv_id', null, null],
            'no type keeps string'     => ['inv_created_at', '42', '42'],
        ];
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/804
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-13
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getWeakValues')]
    public function testMvcModelWeakModeAssign(
        string $property,
        mixed $input,
        mixed $expected
    ): void {
        $models = [
            new InvoicesWeakTypesPublic(),
            new InvoicesWeakTypesSetters(),
        ];

        foreach ($models as $model) {
            $model->assign([$property => $input]);

            $this->assertSame($expected, $model->readAttribute($property));
        }
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/804
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-13
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getRefusedValues')]
    public function testMvcModelWeakModeAssignRefused(
        string $property,
        mixed $input
    ): void {
        $models = [
            new InvoicesWeakTypesPublic(),
            new InvoicesWeakTypesSetters(),
        ];

        foreach ($models as $model) {
            $thrown = false;
            try {
                $model->assign([$property => $input]);
            } catch (TypeError) {
                $thrown = true;
            }

            $this->assertTrue($thrown, get_class($model));
        }
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/804
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-13
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getWeakValues')]
    public function testMvcModelWeakModeAssignWithoutSetters(
        string $property,
        mixed $input,
        mixed $expected
    ): void {
        Settings::set('orm.disable_assign_setters', true);

        $model = new InvoicesWeakTypesSetters();
        $model->assign([$property => $input]);

        $this->assertSame($expected, $model->readAttribute($property));
    }

    /**
     * The setter takes a float. A numeric string from the database goes to
     * the setter, and the setter doubles it.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/804
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-13
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelWeakModeCloneResultMapCallsSetters(): void
    {
        Settings::set('orm.call_setters_on_hydration', true);

        /** @var InvoicesWithSetters $invoice */
        $invoice = Model::cloneResultMap(
            new InvoicesWithSetters(),
            [
                'inv_id'    => 1,
                'inv_total' => '10.5',
            ],
            null
        );

        $this->assertSame(21.0, $invoice->inv_total);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/804
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-13
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getRefusedValues')]
    public function testMvcModelWeakModeCloneResultMapRefused(
        string $property,
        mixed $input
    ): void {
        $this->expectException(TypeError::class);

        Model::cloneResultMap(
            new InvoicesWeakTypesPublic(),
            [
                $property => $input,
            ],
            null
        );
    }

    /**
     * A typed column map casts the value by the column type. The cast value
     * then goes to a property of a different type.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/804
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-13
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelWeakModeCloneResultMapTypedColumnMap(): void
    {
        /** @var InvoicesWeakTypesPublic $invoice */
        $invoice = Model::cloneResultMap(
            new InvoicesWeakTypesPublic(),
            [
                'inv_id'          => '1',
                'inv_status_flag' => '1',
                'inv_title'       => '42',
            ],
            [
                'inv_id'          => ['inv_id', Column::TYPE_INTEGER],
                'inv_status_flag' => ['inv_status_flag', Column::TYPE_TINYINTEGER],
                'inv_title'       => ['inv_title', Column::TYPE_INTEGER],
            ]
        );

        $this->assertSame(1, $invoice->inv_id);
        $this->assertTrue($invoice->inv_status_flag);
        $this->assertSame('42', $invoice->inv_title);
    }

    /**
     * The default value of a column comes from the metadata as a string.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/804
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelWeakModeCreateDefaultValues(): void
    {
        $customer = new CustomersDefaultsTyped();

        $this->assertTrue($customer->create());
        $this->assertSame(1, $customer->cst_status_flag);
    }

    /**
     * The last insert id comes from the adapter as a string.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/804
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelWeakModeCreateIdentity(): void
    {
        $invoice            = new InvoicesWeakTypesPublic();
        $invoice->inv_title = 'x';

        $this->assertTrue($invoice->create());
        $this->assertIsInt($invoice->inv_id);
    }

    /**
     * The related customer has an untyped id. The save copies the id to the
     * typed key of the invoice.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/804
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelWeakModeSaveBelongsToCopiesKey(): void
    {
        $customer                 = new Customers();
        $customer->cst_name_first = 'first';

        $invoice            = new InvoicesWeakTypesPublic();
        $invoice->inv_title = 'x';
        $invoice->customer  = $customer;

        $this->assertTrue($invoice->save());
        $this->assertSame((int) $customer->cst_id, $invoice->inv_cst_id);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/804
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-13
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getWeakValues')]
    public function testMvcModelWeakModeUnderscoreSet(
        string $property,
        mixed $input,
        mixed $expected
    ): void {
        $model            = new InvoicesWeakTypesSetters();
        $model->$property = $input;

        $this->assertSame($expected, $model->readAttribute($property));
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/804
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-13
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getRefusedValues')]
    public function testMvcModelWeakModeUnderscoreSetRefused(
        string $property,
        mixed $input
    ): void {
        $this->expectException(TypeError::class);

        $model            = new InvoicesWeakTypesSetters();
        $model->$property = $input;
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/804
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelWeakModeUnderscoreUnserialize(): void
    {
        $model = new InvoicesWeakTypesPublic();
        $model->__unserialize(
            [
                'attributes' => [
                    'inv_id'    => '42',
                    'inv_total' => '4.5',
                ],
            ]
        );

        $this->assertSame(42, $model->inv_id);
        $this->assertSame(4.5, $model->inv_total);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/804
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelWeakModeUnserialize(): void
    {
        $model = new InvoicesWeakTypesPublic();
        $model->unserialize(
            serialize(
                [
                    'attributes' => [
                        'inv_id'    => '42',
                        'inv_total' => '4.5',
                    ],
                ]
            )
        );

        $this->assertSame(42, $model->inv_id);
        $this->assertSame(4.5, $model->inv_total);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/804
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-13
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getWeakValues')]
    public function testMvcModelWeakModeWriteAttribute(
        string $property,
        mixed $input,
        mixed $expected
    ): void {
        $models = [
            new InvoicesWeakTypesPublic(),
            new InvoicesWeakTypesSetters(),
        ];

        foreach ($models as $model) {
            $model->writeAttribute($property, $input);

            $this->assertSame($expected, $model->readAttribute($property));
        }
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/804
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-13
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getRefusedValues')]
    public function testMvcModelWeakModeWriteAttributeRefused(
        string $property,
        mixed $input
    ): void {
        $this->expectException(TypeError::class);

        (new InvoicesWeakTypesPublic())->writeAttribute($property, $input);
    }
}
