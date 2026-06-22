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

use Phalcon\Mvc\Model\Resultset;
use Phalcon\Mvc\Model\ResultsetInterface;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class SetHydrateModeTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    /**
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
    public function testMvcModelResultsetSetHydrateMode(string $type): void
    {
        $resultset = $this->getResultset($type);

        $this->assertInstanceOf(
            ResultsetInterface::class,
            $resultset->setHydrateMode(Resultset::HYDRATE_ARRAYS)
        );

        $this->assertSame(Resultset::HYDRATE_ARRAYS, $resultset->getHydrateMode());
    }
}
