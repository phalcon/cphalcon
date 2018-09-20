<?php


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
 * @method \Codeception\Lib\Friend haveFriend($name, $actorClass = NULL)
 *
 * @SuppressWarnings(PHPMD)
*/
class IntegrationTester extends \Codeception\Actor
{
    use _generated\IntegrationTesterActions;

    /**
     * Remove files without errors
     *
     * @param mixed $function
     */
    public function removeFilesWithoutErrors($files)
    {
        if (!is_array($files)) {
            $files = array($files);
        }

        foreach ($files as $file) {
            if (file_exists($file) && is_readable($file)) {
                @unlink($file);
            }
        }
    }

    /**
     * Get file name from path
     *
     * @param string $path
     * @param string $separator
     * 
     * @return string
     */
    public function preparePathToFileWithDelimiter($path, $separator) {
        $virtual_str = '';

        if (!is_string($path) || !is_string($separator)) {
            if (is_string($path)) {
                return $path;
            } else {
                return "";
            }
        }

        for ($i = 0; $i < strlen($path); $i++) {
            $ch = $path[$i];
            if ($ch == '\0') {
                break;
            }
            if ($ch == '/' || $ch == '\\' || $ch == ':') {
                $virtual_str .= $separator;
            } else {
                $virtual_str .= strtolower($ch);
            }
        }

        return $virtual_str;
    }
}
