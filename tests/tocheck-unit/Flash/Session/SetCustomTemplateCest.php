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

namespace Phalcon\Test\Unit\Flash\Session;

use Phalcon\Flash\Session;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use UnitTester;

class SetCustomTemplateCest
{
    use DiTrait;

    /**
     * @var array
     */
    protected $classes = [
        'success' => 'successMessage',
        'notice'  => 'noticeMessage',
        'warning' => 'warningMessage',
        'error'   => 'errorMessage',
    ];

    public function _before(UnitTester $I)
    {
        $this->newDi();
        $this->setDiEscaper();
        $this->setDiSessionFiles();
    }

    /**
     * Return flash instance
     */
    protected function getFlash()
    {
        $container = $this->getDi();

        $flash = new Session();
        $flash->setDI($container);
        $flash->setCssClasses($this->classes);

        return $flash;
    }

    /**
     * Test custom template getter/setter
     *
     * @author Phalcon Team <team@phalcon.io>
     * @issue  https://github.com/phalcon/cphalcon/issues/13445
     * @since  2018-10-16
     */
    public function testCustomTemplateGetterSetter(UnitTester $I)
    {
        $flash = $this->getFlash();

        $template = '<span class="%cssClasses%">%message%</span>';

        $flash->setCustomTemplate($template);

        $I->assertEquals(
            $template,
            $flash->getCustomTemplate()
        );
    }
}
