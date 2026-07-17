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
final class SerializeTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->setDiService('phpSerializer');
        $this->seedResultsetFixture();
    }

    /**
     * Every resultset shape serialises to a non-empty string.
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

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testMvcModelResultsetSerialize(string $type): void
    {
        $resultset = $this->getResultset($type);

        $serialized = $resultset->serialize();

        $this->assertIsString($serialized);
        $this->assertNotEmpty($serialized);
    }
}
