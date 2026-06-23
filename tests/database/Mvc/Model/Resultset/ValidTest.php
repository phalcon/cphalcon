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

use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class ValidTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    /**
     * @return array<string, array{0: string, 1: bool}>
     */
    public static function getExamples(): array
    {
        return [
            'simple'  => ['simple', true],
            'complex' => ['complex', true],
            'empty'   => ['empty', false],
        ];
    }

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->seedResultsetFixture();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testMvcModelResultsetValid(string $type, bool $expected): void
    {
        $resultset = $this->getResultset($type);

        $resultset->rewind();

        $this->assertSame($expected, $resultset->valid());
    }
}
