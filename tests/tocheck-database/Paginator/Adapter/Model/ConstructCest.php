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

namespace Phalcon\Test\Integration\Paginator\Adapter\Model;

use IntegrationTester;
use Phalcon\Paginator\Adapter\Model;
use Phalcon\Test\Models\Personnes;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Paginator\Adapter\Model :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-11-1
     */
    public function paginatorAdapterModelConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\Adapter\Model - __construct()');

        $paginator = new Model(
            [
                'model' => Personnes::class,
                'limit' => 10,
                'page'  => 1,
            ]
        );

        $I->assertInstanceOf(Model::class, $paginator);
    }
}
