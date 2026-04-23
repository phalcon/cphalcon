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

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\CustomersVisible;
use Phalcon\Tests\Support\Traits\DiTrait;

final class IsVisibleModelPropertyTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * @return array<array{string, bool}>
     */
    public static function getPublicProperties(): array
    {
        return [
            ['id', true],
            ['document_id', true],
            ['customer_id', true],
            ['first_name', true],
            ['some_field', false],
            ['', false],
            ['protected_field', false],
            ['private_field', false],
        ];
    }

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
    }

    /**
     * @dataProvider getPublicProperties
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-08-12
     */
    public function testMvcModelManagerIsVisibleModelProperty(
        string $property,
        bool $expected
    ): void {
        $manager = $this->getService('modelsManager');

        $actual = $manager->isVisibleModelProperty(
            new CustomersVisible(),
            $property
        );

        $this->assertEquals($expected, $actual);
    }
}
