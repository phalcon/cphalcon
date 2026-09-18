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

namespace Phalcon\Tests\Database\Mvc\Model\Manager;

use Phalcon\Mvc\Model\Exceptions\ReferencedFieldsMismatch;
use Phalcon\Mvc\Model\RelationInterface;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

/**
 * A relation leg that holds one field is a string, so it counts as one field.
 *
 * The second guard of the two through relations compares the intermediate
 * referenced fields against the referenced fields.
 *
 * @see https://github.com/phalcon/cphalcon/issues/17556
 */
#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class RelationFieldsCountTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * @return array<array-key, array<array-key, string>>
     */
    public static function singleLegProvider(): array
    {
        return [
            ['addBelongsTo', 'BelongsTo'],
            ['addHasMany', 'HasMany'],
            ['addHasOne', 'HasOne'],
        ];
    }

    /**
     * A through relation whose two legs line up is accepted.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-03
     */
    public function testMvcModelManagerHasManyToManyBothLegsMatch(): void
    {
        $manager = $this->container->get('modelsManager');
        $invoice = new Invoices();

        $relation = $manager->addHasManyToMany(
            $invoice,
            'inv_id',
            'Phalcon\Tests\Support\Models\InvoicesProducts',
            'inv_id',
            'prd_id',
            'Phalcon\Tests\Support\Models\Products',
            'prd_id',
            ['alias' => 'probeMatched']
        );

        $this->assertInstanceOf(RelationInterface::class, $relation);
    }

    /**
     * The second leg of a many-to-many is checked against the referenced
     * fields, not against the first leg again.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-03
     */
    public function testMvcModelManagerHasManyToManySecondLegMismatch(): void
    {
        $manager = $this->container->get('modelsManager');
        $invoice = new Invoices();

        $this->expectException(ReferencedFieldsMismatch::class);
        $this->expectExceptionMessage('HasManytoMany');

        $manager->addHasManyToMany(
            $invoice,
            'inv_id',
            'Phalcon\Tests\Support\Models\InvoicesProducts',
            'inv_id',
            ['prd_id', 'prd_extra'],
            'Phalcon\Tests\Support\Models\Products',
            'prd_id',
            ['alias' => 'probeManyToMany']
        );
    }

    /**
     * The same check for a has-one-through relation.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-03
     */
    public function testMvcModelManagerHasOneThroughSecondLegMismatch(): void
    {
        $manager = $this->container->get('modelsManager');
        $invoice = new Invoices();

        $this->expectException(ReferencedFieldsMismatch::class);
        $this->expectExceptionMessage('HasOneThrough');

        $manager->addHasOneThrough(
            $invoice,
            'inv_id',
            'Phalcon\Tests\Support\Models\InvoicesProducts',
            'inv_id',
            ['prd_id', 'prd_extra'],
            'Phalcon\Tests\Support\Models\Products',
            'prd_id',
            ['alias' => 'probeOneThrough']
        );
    }

    /**
     * One field on both sides is a match, whatever form each side takes.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-03
     */
    public function testMvcModelManagerRelationStringFieldsMatch(): void
    {
        $manager = $this->container->get('modelsManager');
        $invoice = new Invoices();

        $relation = $manager->addBelongsTo(
            $invoice,
            'inv_cst_id',
            'Phalcon\Tests\Support\Models\Customers',
            ['cst_id'],
            ['alias' => 'probeSingle']
        );

        $this->assertInstanceOf(RelationInterface::class, $relation);
    }

    /**
     * One field on the left and two on the right is a mismatch, not a
     * `TypeError` from counting a string.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-03
     */
    #[DataProvider('singleLegProvider')]
    public function testMvcModelManagerRelationStringFieldsMismatch(
        string $method,
        string $label
    ): void {
        $manager = $this->container->get('modelsManager');
        $invoice = new Invoices();

        $this->expectException(ReferencedFieldsMismatch::class);
        $this->expectExceptionMessage($label);

        $manager->$method(
            $invoice,
            'inv_cst_id',
            'Phalcon\Tests\Support\Models\Customers',
            ['cst_id', 'cst_status_flag'],
            ['alias' => 'probe' . $label]
        );
    }
}
