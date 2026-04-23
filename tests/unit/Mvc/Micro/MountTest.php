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

namespace Phalcon\Tests\Unit\Mvc\Micro;

use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Micro\Collection;
use Phalcon\Tests\AbstractUnitTestCase;

class MountTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcMicroMount(): void
    {
        $micro      = new Micro();
        $collection = new Collection();
        $collection->setHandler(function () {
        });
        $collection->setPrefix('/api');
        $collection->get('/test', function () {
            return 'hello';
        });
        $result = $micro->mount($collection);
        $this->assertInstanceOf(Micro::class, $result);
    }
}
