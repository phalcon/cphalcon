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

use Phalcon\Mvc\Micro\Collection;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

class GetHandlerTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcMicroCollectionGetHandler(): void
    {
        $collection = new Collection();
        $handler    = new stdClass();
        $collection->setHandler($handler);
        $this->assertSame($handler, $collection->getHandler());
    }
}
