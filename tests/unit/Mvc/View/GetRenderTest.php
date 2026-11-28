<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Mvc\View;

use Phalcon\Di\Di;
use Phalcon\Mvc\View;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use stdClass;
use TypeError;

class GetRenderTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewGetRender(): void
    {
        $container = new Di();
        $view      = new View();

        $view->setViewsDir(
            $this->getDirSeparator(Talon::settings()->supportPath('assets/views'))
        );

        $view->setDI($container);

        $actual = $view->getRender(
            'partials',
            'partial',
            [
                'cool_var' => 'abcde',
            ]
        );

        $this->assertEquals(
            'Hey, this is a partial, also abcde',
            $actual
        );
    }

    /**
     * A config callback object that cannot be called throws the TypeError of
     * call_user_func_array().
     *
     * @issue  https://github.com/phalcon/phalcon/issues/815
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    public function testMvcViewGetRenderConfigCallbackNotCallable(): void
    {
        $view = new View();
        $view->setDI(new Di());

        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(
            'call_user_func_array(): Argument #1 ($callback) must be a valid callback, '
            . 'no array or string given'
        );

        $view->getRender('partials', 'partial', [], new stdClass());
    }
}
