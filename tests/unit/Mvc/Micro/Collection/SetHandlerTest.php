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

namespace Phalcon\Tests\Unit\Mvc\Micro\Collection;

use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Micro\Collection;
use Phalcon\Mvc\Micro\CollectionInterface;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Controllers\Micro\Collections\PersonasLazyController;
use stdClass;

class SetHandlerTest extends AbstractUnitTestCase
{
    public function testMicroCollectionsLazy(): void
    {
        $app        = new Micro();
        $collection = new Collection();

        $collection->setHandler(
            PersonasLazyController::class,
            true
        );

        $collection->map('/', 'index');
        $collection->map('/edit/{number}', 'edit');

        $app->mount($collection);

        $app->handle('/');

        $this->assertSame(
            1,
            PersonasLazyController::getEntered()
        );

        $app->handle('/edit/100');

        $this->assertSame(
            101,
            PersonasLazyController::getEntered()
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcMicroCollectionSetHandler(): void
    {
        $collection = new Collection();
        $handler    = new stdClass();
        $result     = $collection->setHandler($handler);
        $this->assertInstanceOf(CollectionInterface::class, $result);
        $this->assertSame($handler, $collection->getHandler());
    }
}
