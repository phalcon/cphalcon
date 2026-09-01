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

use Phalcon\Mvc\Model\Row;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class CurrentTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->seedResultsetFixture();
    }

    /**
     * A simple resultset hydrates models, a complex one rows, an empty one
     * has no current record.
     *
     * @return array<string, array{0: string, 1: string|null}>
     */
    public static function getExamples(): array
    {
        return [
            'simple'  => ['simple', Invoices::class],
            'complex' => ['complex', Row::class],
            'empty'   => ['empty', null],
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
    public function testMvcModelResultsetCurrent(string $type, ?string $expected): void
    {
        $resultset = $this->getResultset($type);

        $resultset->rewind();

        $current = $resultset->current();

        if (null === $expected) {
            $this->assertNull($current);

            return;
        }

        $this->assertInstanceOf($expected, $current);
    }
}
