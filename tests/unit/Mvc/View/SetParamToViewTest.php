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

namespace Phalcon\Tests\Unit\Mvc\View;

use Phalcon\Mvc\View;
use Phalcon\Tests\AbstractUnitTestCase;

class SetParamToViewTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewSetParamToView(): void
    {
        $view   = new View();
        $result = $view->setParamToView('key', 'value');
        $this->assertInstanceOf(View::class, $result);
        $this->assertSame(['key' => 'value'], $view->getParamsToView());
    }
}
