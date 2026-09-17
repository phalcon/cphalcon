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

namespace Phalcon\Tests\Database\Mvc\Model\Resultset;

use Phalcon\Mvc\Model\Exceptions\InvalidReturnedRecord;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class DeleteTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->seedResultsetFixture();
    }

    /**
     * A resultset can only delete complete model objects: a simple resultset
     * deletes its rows, an empty one has nothing to do, while a complex
     * resultset yields rows (not models) and throws InvalidReturnedRecord.
     *
     * @return array<string, array{0: string, 1: bool}>
     */
    public static function getExamples(): array
    {
        return [
            'simple'  => ['simple', false],
            'complex' => ['complex', true],
            'empty'   => ['empty', false],
        ];
    }

    /**
     * @return array<string, array{0: bool}>
     */
    public static function getTransactionExamples(): array
    {
        return [
            'outer transaction'       => [false],
            'stale transaction level' => [true],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testMvcModelResultsetDelete(string $type, bool $throws): void
    {
        $resultset = $this->getResultset($type);

        if ($throws) {
            $this->expectException(InvalidReturnedRecord::class);

            $resultset->delete();

            return;
        }

        $this->assertTrue($resultset->delete());
    }

    /**
     * Deleting a resultset inside an outer transaction must not commit it
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-16
     * @issue  https://github.com/phalcon/cphalcon/issues/17546
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getTransactionExamples')]
    public function testMvcModelResultsetDeleteInsideTransaction(bool $stale): void
    {
        $db = $this->container->get('db');

        if ($stale) {
            $db->begin();
            $db->getInternalHandler()->commit();
        }

        $this->assertTrue($db->begin());
        $this->assertTrue($this->getResultset('simple')->delete());
        $this->assertSame(0, Invoices::count());
        $this->assertSame(1, $db->getTransactionLevel());
        $this->assertTrue($db->isUnderTransaction());

        $this->assertTrue($db->rollback());
        $this->assertSame(3, Invoices::count());
    }
}
