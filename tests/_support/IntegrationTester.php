<?php

use Codeception\Actor;
use Codeception\Lib\Friend;

/**
 * Inherited Methods
 * @method void wantToTest($text)
 * @method void wantTo($text)
 * @method void execute($callable)
 * @method void expectTo($prediction)
 * @method void expect($prediction)
 * @method void amGoingTo($argumentation)
 * @method void am($role)
 * @method void lookForwardTo($achieveValue)
 * @method void comment($description)
 * @method Friend haveFriend($name, $actorClass = null)
 *
 * @SuppressWarnings(PHPMD)
 */
class IntegrationTester extends Actor
{
    use _generated\IntegrationTesterActions;

    /**
     * Define custom actions here
     */

    /**
     * Get file name from path
     *
     * @param mixed $path
     * @param mixed $separator
     *
     * @return string
     */
    public function preparePathToFileWithDelimiter($path, $separator): string
    {
        $virtual = '';

        if (!is_string($path) || !is_string($separator)) {
            if (is_string($path)) {
                return $path;
            } else {
                return '';
            }
        }

        for ($i = 0; $i < strlen($path); $i++) {
            $ch = $path[$i];

            if ($ch == '\0') {
                break;
            }

            if ($ch == '/' || $ch == '\\' || $ch == ':') {
                $virtual .= $separator;
            } else {
                $virtual .= strtolower($ch);
            }
        }

        return $virtual;
    }
}
