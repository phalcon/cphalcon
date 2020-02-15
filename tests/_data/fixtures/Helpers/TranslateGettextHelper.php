<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Helpers;

use Codeception\Example;
use Phalcon\Test\Fixtures\Traits\TranslateGettextTrait;
use Phalcon\Translate\Adapter\Gettext;
use Phalcon\Translate\InterpolatorFactory;
use UnitTester;

class TranslateGettextHelper
{
    use TranslateGettextTrait;

    protected $function = '_';

    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: query()
     *
     * @dataProvider getQueryProvider
     *
     * @author       Ivan Zubok <chi_no@ukr.net>
     * @since        2014-11-04
     */
    public function translateAdapterGettextQuery(UnitTester $I, Example $data)
    {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\Gettext - %s - %s',
                $this->function,
                $data['language']
            )
        );

        $language = $this->getGettextConfig();

        $translator = new Gettext(
            new InterpolatorFactory(),
            $language
        );

        foreach ($data['tests'] as $key => $expected) {
            $I->assertEquals(
                $expected,
                $translator->{$this->function}($key)
            );
        }
    }

    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: query() -
     * variable substitution in string with no variables
     *
     * @dataProvider getQueryProvider
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2014-09-12
     */
    public function translateAdapterGettextVariableSubstitutionNoVariables(UnitTester $I, Example $data)
    {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\Gettext - variable substitution no variables - %s',
                $data['language']
            )
        );

        $language = $this->getGettextConfig();

        $translator = new Gettext(
            new InterpolatorFactory(),
            $language
        );

        foreach ($data['tests'] as $key => $expected) {
            $I->assertEquals(
                $expected,
                $translator->{$this->function}(
                    $key,
                    [
                        'name' => 'my friend',
                    ]
                )
            );
        }
    }

    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: query() -
     * variable substitution in string (one variable)
     *
     * @dataProvider getQueryOneVariable
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2014-09-12
     */
    public function translateAdapterGettextVariableSubstitutionOneVariable(UnitTester $I, Example $data)
    {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\Gettext - variable substitution one variable - %s',
                $data['language']
            )
        );

        $language = $this->getGettextConfig();

        $translator = new Gettext(
            new InterpolatorFactory(),
            $language
        );

        foreach ($data['tests'] as $key => $expected) {
            $actual = $translator->{$this->function}($key, ['name' => 'my friend']);
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: query() -
     * variable substitution in string (two variables)
     *
     * @dataProvider getQueryTwoVariables
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2014-09-12
     */
    public function translateAdapterGettextVariableSubstitutionTwoVariable(UnitTester $I, Example $data)
    {
        $I->wantToTest(
            sprintf(
                'Translate\Adapter\Gettext - variable substitution two variables - %s',
                $data['language']
            )
        );

        $language = $this->getGettextConfig();

        $translator = new Gettext(
            new InterpolatorFactory(),
            $language
        );

        $vars = [
            'song'   => 'Dust in the wind',
            'artist' => 'Kansas',
        ];

        foreach ($data['tests'] as $key => $expected) {
            $I->assertEquals(
                $expected,
                $translator->{$this->function}($key, $vars)
            );
        }
    }

    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: query() - array access and
     * UTF8 strings
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-09-12
     */
    public function testWithArrayAccessAndUTF8Strings(UnitTester $I)
    {
        $language = $this->getGettextConfig();

        $translator = new Gettext(
            new InterpolatorFactory(),
            $language
        );

        $vars = [
            'fname' => 'John',
            'lname' => 'Doe',
            'mname' => 'D.',
        ];

        $I->assertEquals(
            'Привет, John D. Doe!',
            $translator->{$this->function}('Привет, %fname% %mname% %lname%!', $vars)
        );
    }

    /**
     * Data provider for the query tests
     */
    private function getQueryProvider(): array
    {
        return [
            [
                'language' => 'English',
                'code'     => 'en',
                'tests'    => [
                    'hi'  => 'Hello',
                    'bye' => 'Bye',
                ],
            ],
        ];
    }

    /**
     * Data provider for the query one variable substitution
     */
    private function getQueryOneVariable(): array
    {
        return [
            [
                'language' => 'English',
                'code'     => 'en',
                'tests'    => [
                    'hello-key' => 'Hello my friend',
                ],
            ],
        ];
    }

    /**
     * Data provider for the query one variable substitution
     */
    private function getQueryTwoVariables(): array
    {
        return [
            [
                'language' => 'English',
                'code'     => 'en',
                'tests'    => [
                    'song-key' => 'The song is Dust in the wind (Kansas)',
                ],
            ],
        ];
    }
}
