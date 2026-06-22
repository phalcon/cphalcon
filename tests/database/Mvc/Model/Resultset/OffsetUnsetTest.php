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

use Phalcon\Mvc\Model\Exceptions\CursorIsImmutable;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class OffsetUnsetTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    /**
     * A resultset is immutable: offsetUnset() always throws, whatever its
     * shape.
     *
     * @return array<string, array{0: string}>
     */
    public static function getExamples(): array
    {
        return [
            'simple'  => ['simple'],
            'complex' => ['complex'],
            'empty'   => ['empty'],
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
    public function testMvcModelResultsetOffsetUnset(string $type): void
    {
        $resultset = $this->getResultset($type);

        $this->expectException(CursorIsImmutable::class);

        $resultset->offsetUnset(0);
    }
}
