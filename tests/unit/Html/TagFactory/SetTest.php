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

namespace Phalcon\Tests\Unit\Html\TagFactory;

use Phalcon\Html\Escaper;
use Phalcon\Html\Helper\Anchor;
use Phalcon\Html\Helper\Base;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;

final class SetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFilterTagFactorySet(): void
    {
        $escaper = new Escaper();
        $factory = new TagFactory($escaper);

        $service = $factory->newInstance('a');
        $class   = Anchor::class;
        $this->assertInstanceOf($class, $service);

        /**
         * Overriding 'a' with 'base'
         */
        $factory->set('a', Base::class);

        $service = $factory->newInstance('a');
        $class   = Base::class;
        $this->assertInstanceOf($class, $service);
    }
}
