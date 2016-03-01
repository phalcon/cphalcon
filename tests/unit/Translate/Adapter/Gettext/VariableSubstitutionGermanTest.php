<?php

namespace Phalcon\Test\Unit\Translate\Adapter\Gettext;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Translate\Adapter\Gettext;

/**
 * \Phalcon\Test\Unit\Translate\Adapter\Gettext\VariableSubstitutionGermanTest
 * Tests the \Phalcon\Translate\Adapter\Gettext component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Translate\Adapter\Gettext
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class VariableSubstitutionGermanTest extends UnitTest
{
    /**
     * executed before each test
     */
    public function _before()
    {
        parent::_before();

        if (!extension_loaded('gettext')) {
            $this->markTestSkipped('Warning: gettext extension is not loaded');
        }
    }

    /**
     * Tests variable substitution in string - German
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-16
     */
    public function testVariableSubstitutionInStringGerman()
    {
        $this->specify(
            "Translator does not translate to German correctly with passed params",
            function () {
                $translator = new Gettext(
                    [
                        'locale'        => 'de_DE.utf8',
                        'defaultDomain' => 'messages',
                        'directory'     => PATH_DATA . 'translation/gettext'
                    ]
                );

               expect($translator->_('Hello, %name%, it is nice to see you today!', ['name' => 'Phalcon']))->equals('Hallo, Phalcon, es ist schön dich zu sehen heute!');
               expect($translator->t('Hello, %name%, it is nice to see you today!', ['name' => 'Phalcon']))->equals('Hallo, Phalcon, es ist schön dich zu sehen heute!');
            }
        );
    }
}
