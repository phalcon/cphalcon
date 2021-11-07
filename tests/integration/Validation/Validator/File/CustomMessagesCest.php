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

namespace Phalcon\Tests\Integration\Validation\Validator\File;

use IntegrationTester;
use Phalcon\Tests\Fixtures\Traits\ValidationTrait;
use Phalcon\Validation\Validator\File;

/**
 * Class CustomMessagesCest
 */
class CustomMessagesCest
{
    use ValidationTrait;

    /**
     * Tests Phalcon\Validation\Validator\File :: customMessages[]
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function validationValidatorFileCustomMessages(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\File - customMessages[]');

        $options = [
            'maxSize' => '0.5M',
            'messageFileEmpty' => 'File is empty',
            'messageIniSize' => 'Ini size is not valid',
            'messageValid' => 'File is not valid',
        ];
        $file = new File($options);
        $validators = $file->getValidators();

        /** @var File\AbstractFile $validator */
        foreach ($validators as $validator) {
            $messageFileEmpty = $validator->getMessageFileEmpty();
            $messageIniSize = $validator->getMessageIniSize();
            $messageValid = $validator->getMessageValid();

            $I->assertEquals($options['messageFileEmpty'], $messageFileEmpty);
            $I->assertEquals($options['messageIniSize'], $messageIniSize);
            $I->assertEquals($options['messageValid'], $messageValid);
        }
    }
}
