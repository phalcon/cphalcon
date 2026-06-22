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

use Phalcon\Mvc\Model\MetaData\Strategy\Annotations;
use Phalcon\Mvc\Model\MetaData\Strategy\Introspection;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Boutique\Robots;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

final class GetColumnMapsTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * Neither model declares a custom column map, so both strategies return
     * the empty [ordered, reversed] pair.
     *
     * @return array<string, array{0: class-string, 1: class-string}>
     */
    public static function getExamples(): array
    {
        return [
            'introspection' => [Introspection::class, Invoices::class],
            'annotations'   => [Annotations::class, Robots::class],
        ];
    }

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    public function tearDown(): void
    {
        $this->tearDownDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testMvcModelMetadataStrategyGetColumnMaps(
        string $strategyClass,
        string $modelClass
    ): void {
        $strategy = new $strategyClass();
        $model    = new $modelClass();

        $this->assertSame([null, null], $strategy->getColumnMaps($model, $this->container));
    }
}
